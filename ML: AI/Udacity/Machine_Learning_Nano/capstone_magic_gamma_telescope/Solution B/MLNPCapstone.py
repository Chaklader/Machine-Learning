from sklearn.decomposition import RandomizedPCA
from sklearn.cross_validation import train_test_split, cross_val_score
from sklearn.grid_search import GridSearchCV
from sklearn.learning_curve import learning_curve
from sklearn.pipeline import Pipeline
from sklearn.ensemble import RandomForestClassifier
from sklearn.neighbors import KNeighborsClassifier
from sklearn.svm import SVC
from sklearn.metrics import make_scorer, roc_auc_score, roc_curve, auc
from sys import stdout
from time import clock
import matplotlib.pyplot as plt
import pylab
import pandas as pd
import numpy as np
import warnings

class MLNPCapstone(object):

    # Construct a new MLNPCapstone object    
    def __init__(self, 
                 target_name,
                 positive_label,
                 negative_label,
                 missing_data_label='?',
                 pca_max_n=2):

        self._target_name = target_name        # column name of target values
        self._learner = None                   # the name of the algorithm
        self._clf = dict()                     # sklearn classifier objects
        self._missing_data_label = missing_data_label  # ?, NaN, etc.
        self._use_pca = None                   # should we use PCA?
        self._df = None                        # pandas dataframe with the data
        self._train_data = (None, None)        # training data (X, y)
        self._test_data = (None, None)         # testing data (X, y)
        self._positive_label = positive_label  # equals 1
        self._negative_label = negative_label  # equals 0
        self._pca_max_n = pca_max_n            # max number of features to keep
        self._pca_n = None                     # exact num of features for PCA
        self._pca = None                       # Principal Component Analysis
        self._first_classifier = True          # helps with print formatting
        self._fig_count = 1                    # Number of figures plotted
        self._non_outliers = None              # Non-outliers 
 
    # Setters
    def set_learner(self, learner): self._learner = learner
    def set_use_pca(self, use_pca): self._use_pca = use_pca
    def set_pca_n(self, n): self._pca_n = n

    # Return the columns, minus the target column
    def _get_columns(self):
        columns = self._df.columns.tolist()
        return [c for c in columns if c not in [self._target_name]]
   
    # Find non-outliers.  Outliers are considered any data point where the value
    # of the data point in 4 or more columns lies outside 3 standard 
    # deviations from the mean for that column
    def _find_non_outliers(self):
        cols = self._get_columns()
        aux = self._df[cols].apply(lambda x: np.abs(x-x.mean())/x.std() > 3.0)
        self._non_outliers = aux[aux.apply(
                pd.Series.value_counts, axis=1)[0] > 6.0].index.tolist()
 
    # Load the data into a Pandas dataframe and do any necessary preprocessing 
    # on it, including splitting the data into training and test sets
    def load_and_prepare_data(self, datafile):

        print " + Reading in the data...",; stdout.flush()
        self._df = pd.read_csv(datafile)
        print "done.\n + Doing statistical analysis... done."; stdout.flush()
        self.statistical_analysis()
        print " + Plotting a scatter matrix...",; stdout.flush()
        self.scatter_analysis()
        print "done.\n + Preprocessing the data...",; stdout.flush()
        self.preprocess_data()
        print "done.\n + Creating training and test sets...",; stdout.flush()
        self.split_dataframe()

    # Do basic statistical analysis of the data set
    def statistical_analysis(self):
        print "  * Number of data points = %d" % self._df.shape[0]
        print "  * Number of features = %d" % self._df.shape[1]

        self._find_non_outliers()
        print "  * Number of outliers (outlier vals in 4 or more cols) = %d" %\
            (len(self._df)-len(self._non_outliers))
        print "  * Feature analysis:"

        # For each column gather the min and max, the mean and median, and the
        # standard deviation       
        cols = self._get_columns()
        min_vals = [self._df[c].min() for c in cols]
        max_vals = [self._df[c].max() for c in cols]
        mean_vals = [self._df[c].mean() for c in cols]
        median_vals = [self._df[c].median() for c in cols]
        std_vals = [self._df[c].std() for c in cols]

        print
        print '     {:13s}  {:7s}   {:7s}   {:7s}   {:7s}    {:7s}'.format(
            'FEATURE', 'MIN', 'MAX', 'MEAN', 'MEDIAN', 'STD')
        for c in cols:
            feat = c
            min, max = self._df[c].min(), self._df[c].max()
            mean, median = self._df[c].mean(), self._df[c].median()
            std = self._df[c].std()
            print '     {:10s} {:7.2f}   {:7.2f}   {:8.2f}   {:9.2f}'\
                '   {:5.2f}'.format(feat, min, max, mean, median, std)
        print
    
    # Plot a scatter matrix of the data 
    def scatter_analysis(self):
        cols = self._get_columns()
 
        with warnings.catch_warnings():
            warnings.simplefilter("ignore")
            axes = pd.tools.plotting.scatter_matrix(
                                        self._df.sample(frac=0.1, replace=True),
                                        alpha=0.2, 
                                        diagonal='kde')
            fig = plt.figure(self._fig_count)
            fig.suptitle('Scatter Matrix Plot of Data')
            [plt.setp(item.yaxis.get_majorticklabels(), 
                      'size', 4) 
                for item in axes.ravel()]
            [plt.setp(item.xaxis.get_majorticklabels(), 
                      'size', 8) 
                for item in axes.ravel()]
            [plt.setp(item.yaxis.get_label(), 
                      'size', 8)
                for item in axes.ravel()]
            [plt.setp(item.xaxis.get_label(), 
                      'size', 8)
                for item in axes.ravel()]
            plt.show()
            self._fig_count += 1
 
    # Use PCA to analyze the data set - knowing the number of principal 
    # components can help us choose a model
    def pca_analysis(self):
        if not self._use_pca:
            return
 
        print "done.\n + Using PCA to analyze the data...",; stdout.flush()

        cols = self._get_columns()
        
        (X_train, _) = self._train_data
        if not self._pca:
            self._pca = RandomizedPCA(
                            n_components=self._pca_max_n, 
                            whiten=True,
                            random_state=42)
            self._pca.fit(X_train)

        # NOTE:  plot code stolen from sklearn example: http://bit.ly/1X8ZsUw
        fig = plt.figure(self._fig_count, figsize=(4,3))
        plt.clf()
        plt.axes([.2, .2, .7, .7])
        plt.plot(self._pca.explained_variance_ratio_)
        fig.suptitle('RandomizedPCA Analysis')
        plt.axis('tight')
        plt.xlabel('Component')
        plt.ylabel('Explained Variance Ratio')
        plt.show()
        self._fig_count += 1

        # Reset the PCA object, since we will need to set the exact number
        # of components we want to use if and when we use it again
        self._pca = None
        
    # Train a classifier pipeline that may or may not use PCA or other
    # feature selection methods
    def train_classifier(self, refine=False):

        params = dict() 
        pipeline_steps = []

        # If we're doing PCA, create the PCA object and add it to the pipeline
        # and add the parameters  
        if self._use_pca:
            if not self._pca:
                # If haven't set the number of components for PCA, do search
                if self._pca_n == None:
                    self._pca = RandomizedPCA(random_state=42)
                    params['pca__n_components'] =\
                        [i for i in range(2,self._pca_max_n+1)]
                    params['pca__whiten'] = [True, False]
                    params['pca__iterated_power'] = [2,3,4,5]
                else:
                    self._pca = RandomizedPCA(
                                    n_components = self._pca_n,
                                    random_state=42)

            pipeline_steps.append(('pca', self._pca))

        # Add the correct learner to the pipeline, along with its parameters 
        if self._learner == 'rfc':
            rfc = RandomForestClassifier(random_state=42)
            if not refine:
                params['rfc__n_estimators'] = [i for i in range(6,15)]
                params['rfc__max_depth'] = [i for i in range(1,11)]
                params['rfc__criterion'] = ['gini','entropy']
            else:
                # Use the parameters we've already trained
                for (k, v) in self._clf['rfc'].best_params_.iteritems():
                    params[k] = [v] 
                params['rfc__max_features'] = [i for i in range(1,10)]
                params['rfc__min_samples_split'] = [4,5,6]
                params['rfc__min_samples_leaf'] = [1,2,3]
                params['rfc__bootstrap'] = [True, False] # can't do oob_score
                #params['rfc__oob_score'] = [True, False] # can't do bootstrap
                params['rfc__warm_start'] = [True, False]
            pipeline_steps.append(('rfc', rfc))
        elif self._learner == 'svc':
            svc = SVC(random_state=42)
            params['svc__kernel'] = ['poly', 'rbf']
            params['svc__degree'] = [2, 3, 4, 5]
            params['svc__C'] = [1.0, 10.0, 100.0, 1000.0]
            pipeline_steps.append(('svc', svc))
        elif self._learner == 'knc':
            knc = KNeighborsClassifier()
            params['knc__n_neighbors'] = [5, 10, 15, 20]
            params['knc__weights'] = ['uniform', 'distance']
            params['knc__algorithm'] = ['ball_tree', 'kd_tree', 'auto']
            params['knc__leaf_size'] = [10, 20, 30] 
            pipeline_steps.append(('knc', knc))
        else:
            raise Exception('Undefined learner!')
 
        pipe = Pipeline(steps=pipeline_steps)

        # Perform a grid search to find the best learning parameters
        (X, y) = self._train_data
        clf = GridSearchCV(pipe, params, scoring=make_scorer(roc_auc_score))
        start = clock()
        clf.fit(X, y)
        end = clock()

        # Store the classifier in the classifier dictionary
        self._clf[self._learner] = clf

        self._first_classifier = False

        # Return the time it took to train the classifier
        return (end - start)

    # Do any needed preprocessing of the data (normalization, addressing 
    # missing values, centering, etc)
    def preprocess_data(self):

        cols = self._get_columns()
       
        # Use interpolation to handle missing data
        self._df.interpolate()

        # Normalize and center the data
        self._df[cols] =\
            self._df[cols].apply(lambda x: (x-x.mean())/(x.max()-x.min()))
        
        # Remove outliers
        self._df = self._df.loc[self._non_outliers]

        # Set the positive label to 1 and the negative label to 0
        self._df.replace(to_replace=self._positive_label, value=1, inplace=True)
        self._df.replace(to_replace=self._negative_label, value=0, inplace=True)

    # Split the dataframe into X (the data) and y (the target), for both 
    # training and testing
    def split_dataframe(self):

        cols = self._get_columns()
        X, y = self._df[cols].values, self._df[self._target_name].values

        X_train, X_test, y_train, y_test = train_test_split(
                                                X, y, 
                                                test_size=0.2,
                                                random_state=42)

        self._train_data = (X_train, y_train)
        self._test_data = (X_test, y_test)

    # Run all of the steps to produce a classifier from the given data
    def run(self, verbose=True, refining=False, plot_learning_curve=False):

        if self._first_classifier:
            print "done.\n",
        print " + Training classifier (learner = %s, use_pca = %r)..." \
            % (self._learner, self._use_pca),; stdout.flush()
        training_time = self.train_classifier(refine=refining)
        
        if verbose:
            print "done\n   * Best parameters:" 
            for (k, v) in self._clf[self._learner].best_params_.iteritems():
                print "     - " + k[k.find("__")+2:] + " = " + str(v)

            # Print out our precision (swallow the warning about changed 
            # behavior of the scoring function)
            (X_test, y_test) = self._test_data
            start = clock()
            with warnings.catch_warnings():
                warnings.simplefilter("ignore")
                score = self._clf[self._learner].score(X_test, y_test)
            end = clock()
            testing_time = (end - start)

            print
            print "   * roc_auc_score (learner = %s): %f" %\
                (self._learner, score)
            print "   * Training time: %f seconds" % training_time   
            print "   * Testing time: %f seconds" % testing_time 
            print

            if plot_learning_curve:
                self.plot_learning_curve()

    # Plot the learning curve for this learner
    # (ref: http://scikit-learn.org/stable/auto_examples/model_selection/...
    #           plot_learning_curve.html)
    def plot_learning_curve(self):
        print " + Plotting learning curve (this will take some time)...",
 
        (X_train, y_train) = self._train_data

        plt.figure()
        plt.title("Learning curve (%s)" % self._learner)
        plt.xlabel("Training examples")
        plt.ylabel("Score")
        train_sizes, train_scores, test_scores = learning_curve(
                                                    self._clf[self._learner],
                                                    X_train, y_train,
                                                    cv=5)
        train_scores_mean = np.mean(train_scores, axis=1)
        train_scores_std = np.std(train_scores, axis=1)
        test_scores_mean = np.mean(test_scores, axis=1)
        test_scores_std = np.std(test_scores, axis=1)
        plt.grid()

        plt.fill_between(
            train_sizes,
            train_scores_mean - train_scores_std,
            train_scores_mean + train_scores_std,
            alpha=0.1,
            color="r")
        plt.fill_between(
            train_sizes, 
            test_scores_mean - test_scores_std,
            test_scores_mean + test_scores_std,
            alpha=0.1,
            color="g")
        plt.plot(
            train_sizes, train_scores_mean, 
            'o-', color="r",
            label="Training score")
        plt.plot(
            train_sizes, test_scores_mean,
            'o-', color="g",
            label="Cross-validation score")
      
        plt.legend(loc="best")
        plt.show()
  
        print "done."
                         
    # Plot the ROC curve that results from each of our classifiers
    def plot_roc(self):

        for learner, clf in self._clf.iteritems():
            # Make the predictions 
            (X_test, y_test) = self._test_data 
            y_pred = clf.predict(X_test)

            # Get (f)alse (p)ositive (r)ate, (t)rue (p)ositive (r)ate
            fpr, tpr, _ = roc_curve(y_test, y_pred)
      
            # Add this classifier's results to the plot
            plt.plot(fpr, tpr, label='%s (area = %0.2f)'\
                % (learner, auc(fpr, tpr)))
            
        # Now do the plot
        # NOTE:  plot code stolen from scikit-learn docs (http://bit.ly/236k6M3)
        plt.xlim([-0.05, 1.05])
        plt.ylim([-0.05, 1.05])
        plt.xlabel('False Positive Rate')
        plt.ylabel('True Positive Rate')
        plt.title('Receiver Operating Characteristic (ROC)')
        plt.legend(loc="lower right")
        plt.show()

    def cross_validate(self):
        clf = self._clf[self._learner]
        (X_train, y_train) = self._train_data

        print " + Cross-validating classifier (learner = %s)..." \
            % self._learner,; stdout.flush()
        scores = cross_val_score(
                        self._clf[self._learner],
                        X_train, y_train,
                        scoring=make_scorer(roc_auc_score),
                        cv=3)
        print "done.\n   * Scores: %r" % scores

