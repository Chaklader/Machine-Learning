


#Applied Statistics in transport, WS2011/12
#Seminar "Hypothesis-driven data analysis" 

#NUMBER 3
#Lab session inferential statistics, case study MID2008, material for guest lecture Tina Gehlert
#Goal: do inferential analyses/tests with MID2008, extended person dataset

#This is r-code with all the commands, including the commands for the student tasks
#You find the same code without the commands for the student tasks in MID2008_AS_GuestLecture_Inferential_20120128student.R 

setwd("u:\\")

#Data sets in the folder ExLab5_MID2008_Descriptive\\:
#p2008_descriptive1.Rdata: created in MID2008_AS_GuestLecture_InputDescriptive_20120202student.R, basis for the code in this file

#--------------------------------------------------------------
#Notation:
#IV: independent variable
#DV: dependent variable 
#--------------------------------------------------------------
 
#------------------------------------------------------------
#create the copy of the data set for your work:
load("L:\\LS_Verkehrstechnik\\AppliedStatistics\\ExLabTina_20120203\\p2008_descriptive1.Rdata")
p2008_inferential<-p2008_descriptive1
rm(p2008_descriptive1)
ls()

#------------------------------------------------------------
#have a first look at your dataset
str(p2008_inferential)
names(p2008_inferential)
head(p2008_inferential)
 

#---------
#These are the questions asked to choose the right statistical test

#What are you testing for? 
#Relations vs. Differences
#One-tailed vs. Two-tailed

#What type of data do you have?
#Number of variables 
#Level of scale of variables
#Distribution of variables (most important normal distribution)

#Do you have related or unrelated data?
#Paired vs. independent observations

#1. Correlation analysis 

#Tests for relations
#bivariate analyses = 1 IV and 1 DV
#see example Case study H1

#2. Tests

#Assumptions:
#Test differences between two groups

#---------
#bivariate analysis: 
#1 IV  hp_pkwfs: Car drivers license (from p061_3 entry in the household interview); 
#1 DV NoTripsPerson, number of trips
#IV: dichotomous (yes/no); DV: metric scale (interval or ratio)
#Distribution: DV normally distributed
#Methods studies show that t-test is robust agains violation of ND 
#independent observations
#Equal variances

#---------
#Example :   

#H 3: Car availability relates to the number of trips, trip distance and trip time 

#Refined for difference testing: Is there a difference in number of trips for people with and without a driving licence
#1 IV: p061_3: Car drivers license 
#1 DV: NoTripsPerson, no normal distribution
#but central limit theorem n> 30 = normal distribution

#Test: T-Test
   
#---------
#p061_3: Drivers license for a car/station wagon
str(p2008_inferential$p061_3) #Factor w/ 10 levels "NichtGenannt",..: 2 2 2 2 2 2 2 1 2 2 ...
summary(p2008_inferential$p061_3) #

#insert missing values
p2008_inferential$p061_3<-replace(p2008_inferential$p061_3,p2008_inferential$p061_3=="102" 
      | p2008_inferential$p061_3=="103" | p2008_inferential$p061_3=="104"
      | p2008_inferential$p061_3=="105" | p2008_inferential$p061_3=="107"
      | p2008_inferential$p061_3=="109" | p2008_inferential$p061_3=="111"
      | p2008_inferential$p061_3=="403", NA)

summary(p2008_inferential$p061_3) #
table(is.na(p2008_inferential$p061_3)==F)
levels(p2008_inferential$p061_3)
levels(p2008_inferential$p061_3)[3:10]<-"Genannt" #summarize levels with 0 cases
summary(p2008_inferential$p061_3) #

save(p2008_inferential, file="p2008_inferential.Rdata")

#---------
#DV:  NoTripsPerson
#calculate: Descriptives with mean, variance and standard deviation, skew and curtosis

with(p2008_inferential,table(NoTripsPerson))

par(mfrow=c(1,1))
barplot(table(p2008_inferential$NoTripsPerson)) 

summary(p2008_inferential$NoTripsPerson) #
with(p2008_inferential,table(NoTripsPerson))
#standard deviation
sd(p2008_inferential$NoTripsPerson,na.rm=T) #

#Result: 
#Full range of values (min 1, max 12)
#mean, sd

#---------
#Calculate Descriptives for both groups separately (1= driving license yes,  2 = driving license no)
p061_3_NichtGenannt<-p2008_inferential[p2008_inferential$p061_3=="NichtGenannt" & is.na(p2008_inferential$p061_3)==F,]
summary(p061_3_NichtGenannt$p061_3) #0 NAs 
#descriptive measures for NoTripsPerson
summary(p061_3_NichtGenannt$NoTripsPerson)
sd(p061_3_NichtGenannt$NoTripsPerson, na.rm=T)

p061_3_Genannt<-p2008_inferential[p2008_inferential$p061_3=="Genannt" & is.na(p2008_inferential$p061_3)==F,]
summary(p061_3_Genannt$p061_3)
#descriptive measures for NoTripsPerson
summary(p061_3_Genannt$NoTripsPerson)
sd(p061_3_Genannt$NoTripsPerson, na.rm=T)

#---------
#boxplot
boxplot(p2008_inferential$NoTripsPerson ~ p2008_inferential$p061_3, main = "NoTripsPerson by p061_3")

#---------
#Results:
#Driving licence yes (N=33224) 
#No of trips: mean=3.954, SD=2.15, Min= 1, max = 12

#Driving license no (N=5080)
#No of trips: means=3.305, SD=1.77, Min =1, Max = 12

#People with no driving licence report a smaller average number of trips
#we have different sample sizes, T-test only robuts with different sample sizes if variances of both groups are equal
#test of equality of variance necessary 
#in addition to T-test, Is that difference statistically significant (or just random variation) 

#---------
#Remember from class:
#Fisher's F test: compares two sample variances.
#Should be done before comparing two sample means: test whether two variances are significantly 
#different (homo-/heteroscedasticity).
#Procedure: divide the larger by the smaller variance
#In order to be different, the ratio will need to be significantly bigger than 1 (because the larger variance goes on top, 
#in the numerator).
#Decide on the significance of the variance ratio with the help of the critical value of the variance ratio: 
#the critical value of the Fisher's F test.

#R-function for getting critical values: "qf(p, df1, df2)": quantiles of the F distribution
#var.test(x, y, ratio = 1,alternative = c("two.sided", "less", "greater"), conf.level = 0.95, ...)

var.test(p061_3_Genannt$NoTripsPerson,p061_3_NichtGenannt$NoTripsPerson,na.action=na.omit)

#The two variances are not equal, you have seen this in the boxplot.

#---------
#Do the t.test:
#t.test(x, y = NULL,alternative = c("two.sided", "less", "greater"),mu = 0, paired = FALSE, var.equal = FALSE,conf.level = 0.95, ...)

t.test(p061_3_Genannt$NoTripsPerson,p061_3_NichtGenannt$NoTripsPerson,var.equal = FALSE)

#The test is significant, that means the descriptive differenes are statistically signficant (no random variation)
#We would report the T value 20.6865
#However, T-test not robust if no ND, different sample sizes & unequal variances
#if variance is bigger in smaller sample (not the case here), the test is in favour of H1 (there is a difference, 
#even if is there is non = progressiv testing)

#In that case a more conservative strategy is recommened, thus to use a non-parametric test
#a non parametric test does not makes assumptions regarding the distribution, it uses ranks as basis for calculation

#---------
#Test: Wilcoxon-Test
#Remember from class:
#Wilcoxon-test: Non-parametric alternative to Student's t test.
#Can be used for ordinal variables; if interval data is non-normal; when sample size is small
#Procedure unpaired test: 
#Put both samples in one array, with their sample names clearly attached.
#Sort the aggregate list, taking care to keep the sample labels with their respective values.
#Assign a rank to each value, with ties getting the appropriate average rank(two way ties get: (rank i+ (rank i+1))/2, three-way ties: (rank i+(rank i+1)+(rank i+2))/3 and so on.
#Finally the ranks are added up for each of the two samples, and significance is assessed on size of the smaller sum of ranks.
#Pairs with differences equal to zero are not considered for this calculation; is the share of such pairs high, this is a strong indication that the null hypothesis is true.

#wilcox.test(x, y = NULL,alternative = c("two.sided", "less", "greater"), mu = 0, paired = FALSE, conf.level = 0.95, ...)

wilcox.test(p061_3_Genannt$NoTripsPerson,p061_3_NichtGenannt$NoTripsPerson)

#the Wilcoxon-Test still gives a significant result: 

#Thus we can state that people with driviing license do have on average a statistically significant higher number 
#of trips than people without a driving license

#---------
#Student task: 
#T-tests / Wilcoxon-Test with trip distance (TripDistPerson) and trip duration (TripTimePerson) as DV

#---------
#Trip distance, variable TripDistPerson
names(p2008_inferential)
#Calculate Descriptives for both groups separately (1= driving license yes,  2 = driving license no)

p061_3_NichtGenannt<-p2008_inferential[p2008_inferential$p061_3=="NichtGenannt" & is.na(p2008_inferential$p061_3)==F,]
summary(p061_3_NichtGenannt$p061_3) #0 NAs 
#descriptive measures for TripDistPerson
summary(p061_3_NichtGenannt$TripDistPerson)
sd(p061_3_NichtGenannt$TripDistPerson, na.rm=T)

p061_3_Genannt<-p2008_inferential[p2008_inferential$p061_3=="Genannt" & is.na(p2008_inferential$p061_3)==F,]
summary(p061_3_Genannt$p061_3)
#descriptive measures for TripDistPerson
summary(p061_3_Genannt$TripDistPerson)
sd(p061_3_Genannt$TripDistPerson, na.rm=T)

#---------
#boxplot
par(mfrow=c(1,1))
boxplot(p2008_inferential$TripDistPerson ~ p2008_inferential$p061_3, main = "TripDistPerson by p061_3")
#---------
#Fisher's F test: compares two sample variances.
var.test(p061_3_Genannt$TripDistPerson,p061_3_NichtGenannt$TripDistPerson,na.action=na.omit)
#The two variances are not equal, p-value < 2.2e-16.
#---------
t.test(p061_3_Genannt$TripDistPerson,p061_3_NichtGenannt$TripDistPerson,var.equal = FALSE)
#---------
#Wilcoxon-Test
wilcox.test(p061_3_Genannt$TripDistPerson,p061_3_NichtGenannt$TripDistPerson) #p-value < 2.2e-16

#---------
#Trip duration, variable TripTimePerson
names(p2008_inferential)
#Calculate Descriptives for both groups separately (1= driving license yes,  2 = driving license no)

p061_3_NichtGenannt<-p2008_inferential[p2008_inferential$p061_3=="NichtGenannt" & is.na(p2008_inferential$p061_3)==F,]
summary(p061_3_NichtGenannt$p061_3) #0 NAs 
#descriptive measures for TripTimePerson
summary(p061_3_NichtGenannt$TripTimePerson)
sd(p061_3_NichtGenannt$TripTimePerson, na.rm=T)

p061_3_Genannt<-p2008_inferential[p2008_inferential$p061_3=="Genannt" & is.na(p2008_inferential$p061_3)==F,]
summary(p061_3_Genannt$p061_3)
#descriptive measures for TripTimePerson
summary(p061_3_Genannt$TripTimePerson)
sd(p061_3_Genannt$TripTimePerson, na.rm=T)

#---------
#boxplot
par(mfrow=c(1,1))
boxplot(p2008_inferential$TripTimePerson ~ p2008_inferential$p061_3, main = "TripTimePerson by p061_3")
#---------
#Fisher's F test: compares two sample variances.
var.test(p061_3_Genannt$TripTimePerson,p061_3_NichtGenannt$TripTimePerson,na.action=na.omit)
#The two variances are not equal, p-value < 2.2e-16.
#---------
t.test(p061_3_Genannt$TripTimePerson,p061_3_NichtGenannt$TripTimePerson,var.equal = FALSE)
#---------
#Wilcoxon-Test
wilcox.test(p061_3_Genannt$TripTimePerson,p061_3_NichtGenannt$TripTimePerson) #

#End student task
#---------




