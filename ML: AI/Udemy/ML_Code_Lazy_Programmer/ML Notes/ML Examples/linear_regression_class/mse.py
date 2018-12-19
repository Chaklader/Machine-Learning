#You can for example create a scorer that computes MSE score and R2 score 
# and choose which one you're gonna use in the GridSearch, however you will 
# be able to see the two scores, if you insert a print in each score function. 
# Here is a starter code:



from sklearn.metrics import r2_score, mean_squared_error, make_scorer
from sklearn.grid_search import GridSearchCV
from sklearn.linear_model import Ridge

def MSE(y_true,y_pred):
    mse = mean_squared_error(y_true, y_pred)
    print 'MSE: %2.3f' % mse
    return mse

def R2(y_true,y_pred):    
     r2 = r2_score(y_true, y_pred)
     print 'R2: %2.3f' % r2
     return r2

def two_score(y_true,y_pred):    
    MSE(y_true,y_pred) #set score here and not below if using MSE in GridCV
    score = R2(y_true,y_pred)
    return score

def two_scorer():
    return make_scorer(two_score, greater_is_better=True) # change for false if using MSE

model = Ridge()
param_grid = {'alpha':[0.1,1,10]}
X_train = [[1,2],[1,5],[-3,2],[3,7],[-1,1],[0,-1]]
y_train = [1,0,1,0,3,5]
grid = GridSearchCV(model, param_grid, scoring=two_scorer())

grid.fit(X_train, y_train)
best_params = grid.best_params_
model = grid.best_estimator_
score = grid.best_score_

for item in grid.grid_scores_:
    print "\t%s %s %s" % ('\tGRIDSCORES\t',  "R" , item)

print '%s\tHP\t%s\t%f' % ("R" , str(best_params) ,abs(score))



# And it's the output:

# MSE: 2.376
# R2: -8.506
# MSE: 6.246
# R2: -23.985
# MSE: 7.304
# R2: -6.304
# MSE: 2.226
# R2: -7.904
# MSE: 5.058
# R2: -19.230
# MSE: 7.755
# R2: -6.755
# MSE: 1.786
# R2: -6.144
# MSE: 1.776
# R2: -6.104
# MSE: 9.660
# R2: -8.660
#                 GRIDSCORES   R mean: -12.93166, std: 7.86753, params: {'alpha': 0.1}
#                 GRIDSCORES   R mean: -11.29644, std: 5.62964, params: {'alpha': 1}
#                 GRIDSCORES   R mean: -6.96916, std: 1.19536, params: {'alpha': 10}
# R   HP  {'alpha': 10}   6.969163