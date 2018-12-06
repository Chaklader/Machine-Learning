

#Applied Statistics in transport, WS2011/12
#Seminar "Hypothesis-driven data analysis" 

#NUMBER 2
#Lab session descriptives, case study MID2008, material for guest lecture Tina Gehlert
#Goal: do descriptive analyses with MID2008, extended person dataset

#This is r-code with all the commands, including the commands for the student tasks
#You find the same code without the commands for the student tasks in MID2008_AS_InputDescriptive_20120124studenttasks.R 

setwd("u:\\")

#Data sets in the folder ExLab5_MID2008_Descriptive\\:
#p2008extendedASOriginal.Rdata: the same as p2008 but with more variables and some coded variables, prepared by Regine Gerike for the course Applied Statistics 
#p2008extendedAS.Rdata: your working file in this r-file, based on p2008extendedASOriginal

#--------------------------------------------------------------
#Notation:
#IV: independent variable
#DV: dependent variable 
#--------------------------------------------------------------
 
#------------------------------------------------------------
#create the copy of the data set for your work:
load("L:\\LS_Verkehrstechnik\\AppliedStatistics\\ExLabTina_20120203\\p2008extendedASFor20120203.Rdata")
p2008_descriptive<-p2008extendedAS
save(p2008_descriptive, file="p2008_descriptive.Rdata")
rm(p2008extendedAS)
ls()

#------------------------------------------------------------
#have a first look at your dataset
str(p2008_descriptive)
names(p2008_descriptive)
head(p2008_descriptive)

#------------------------------------------------------------
#Data input and preparation
#done, see our lab exercises in November in ExLab3_DataInputPreparation, ExLab5_MID2008_Descriptive,
#see WarmUp this morning

#------------------------------------------------------------
#Case study "Accessibility and travel behaviour"
#Research question: How does accessibility relate to individual travel behaviour? 

#Hypothesis 1:
#The more often people use the bicycle 
#the better the accessibility by bicycle is assessed for all trip purposes. 

#File selection: 
#Person data file as main file, since unit of analysis is person

#Variable selection: 

#IV : 
#p033: Frequency of bicycle use

#DV:
#p0412_1: Accessibility of workplace by bicycle
#p0412_2: Accessibility of apprenticeship location by bicycle
#p0412_3: Accessibility of school by bicycle
#p0412_4: Accessibility of shops |businesses (daily shopping) by bicycle

#Sample description: 
#hp_sex: Gender (missing data supplemented from household interview)
#hp_alter: Age (missing data supplemented from household interview)
#hp_altg1: Age group (variable 1)
#hp_altg2: Age group (variable 2)
#hp_altg3: Age group (variable 3)


#DATA PREPARATION

#Task 1 Verifying data 

#Range checks
#for the ordinal IV variable calculate frequencies (min, max, mean etc.)

#p033: Frequency of bicycle use
str(p2008_descriptive$p033) #Factor w/ 6 levels "Tägl","1bis3Woche",..: 3 1 3 2 NA 3 2 1 5 6 ....
summary(p2008_descriptive$p033) 
table(p2008_descriptive$p033) #
table(is.na(p2008_descriptive$p033)==T) #check for missing values

#Results:
#p033 : min max = all factor levels, that corresponds with valid range from codebook
#38577 valid cases, 22136 (defined!) missing values, no undefined missings

#------------------------------------------------------------
#calculate Frequencies for variables on accessibility

#---------
#p0412_1: Accessibility of workplace by bicycle
str(p2008_descriptive$p0412_1) #Factor w/ 6 levels "SehrGut","Gut",..: 2 6 6 1 6 1 4 6 6 1 ...
summary(p2008_descriptive$p0412_1) 
table(p2008_descriptive$p0412_1) #for factor variables similar to summary but without missing values
table(is.na(p2008_descriptive$p0412_1)==T) #check for missing values

#Results:
#p0412_1 : min max = all factor levels, that corresponds with valid range from codebook
#19089 valid cases, 41624 (defined!) missing values, no undefined missings

save(p2008_descriptive, file="p2008_descriptive.Rdata")

#---------
#Student task

#p0412_2: Accessibility of apprenticeship location by bicycle
str(p2008_descriptive$p0412_2) #Factor w/ 6 levels "SehrGut","Gut",..: NA NA NA NA NA NA NA 1 NA NA ...
summary(p2008_descriptive$p0412_2) 
table(p2008_descriptive$p0412_2) #for factor variables similar to summary but without missing values
table(is.na(p2008_descriptive$p0412_2)==T) #check for missing values

#Results:
#p0412_2: min max = all factor levels, that corresponds with valid range from codebook
#646 valid cases, 60067 (defined!) missing values, no undefined missings, 18776 cases with p0412_2=NA 
#come from level 507: not employed, 14801 cases with p0412_2=NA come from 102: adult,
#4461 cases with p0412_2=NA come from 105: child of age<10

#end student task
#---------

#---------
#p0412_4: Accessibility of shops |businesses (daily shopping) by bicycle
str(p2008_descriptive$p0412_4) #Factor w/ 6 levels "SehrGut","Gut",..: 2 3 3 1 NA 1 2 2 2 2 ...
summary(p2008_descriptive$p0412_4) 
table(p2008_descriptive$p0412_4) #for factor variables similar to summary but without missing values
table(is.na(p2008_descriptive$p0412_4)==T) #check for missing values

#Results:
#p0412_4: min max = all factor levels, that corresponds with valid range from codebook,
#most cases with very good or good accessibility
#38394 valid cases, 22319 (defined!) missing values, no undefined missings,
#14801 cases with p0412_4=NA come from 102: adult

#---------
#for the Sample description calculate Frequencies for nominal age variable 
#(hp_altg1) and Descriptives for age

#---------
#hp_altg1, Age group (variable 1)
str(p2008_descriptive$hp_altg1) #Factor w/ 10 levels "<5","<9","<13",..: 7 7 7 6 3 7 6 5 4 6 ...
summary(p2008_descriptive$hp_altg1) 
table(p2008_descriptive$hp_altg1) #for factor variables similar to summary but without missing values
table(is.na(p2008_descriptive$hp_altg1)==T) #check for missing values

#---------
#hp_alter, Age
str(p2008_descriptive$hp_alter) #int [1:60713] 47 52 58 37 12 46 44 18 16 25 ...
summary(p2008_descriptive$hp_alter) 
table(p2008_descriptive$hp_alter) #
table(is.na(p2008_descriptive$hp_alter)==T) #check for missing values

#Results: sample size corresponds with ordinal age variables hp_altgx:
#112 NAs in hp_altg1 and also in hp_alter.
#min 0, max 101 - plausible values 

#---------
save(p2008_descriptive, file="p2008_descriptive.Rdata")


#---------
#Student task

#hp_sex, gender 

str(p2008_descriptive$hp_sex) #Factor w/ 3 levels "m","w","k.A.": 1 2 1 2 2 1 2 1 2 1 ...
summary(p2008_descriptive$hp_sex) 
table(p2008_descriptive$hp_sex) #for factor variables similar to summary but without missing values
table(is.na(p2008_descriptive$hp_sex)==T) #check for missing values

#hp_altg2, Age group (variable 2)
str(p2008_descriptive$hp_altg2) #Factor w/ 10 levels "<9","<19","<29",..: 5 6 6 4 2 5 5 2 2 3 ...
summary(p2008_descriptive$hp_altg2) 
table(p2008_descriptive$hp_altg2) #for factor variables similar to summary but without missing values
table(is.na(p2008_descriptive$hp_altg2)==T) #check for missing values

#no missings but k.A. are in fact missings, we should recode them
p2008_descriptive$hp_altg2<-replace(p2008_descriptive$hp_altg2,p2008_descriptive$hp_altg2=="k.A.", NA)

summary(p2008_descriptive$hp_altg2) 
table(is.na(p2008_descriptive$hp_altg2)==T) #112 NAs

#---------
#hp_altg3, Age group (variable 3)
str(p2008_descriptive$hp_altg3) #Factor w/ 12 levels "<4","<10","<13",..: 7 8 8 6 3 7 7 5 4 5 ...
summary(p2008_descriptive$hp_altg3) 
table(p2008_descriptive$hp_altg3) #for factor variables similar to summary but without missing values
table(is.na(p2008_descriptive$hp_altg3)==T) #check for missing values

#no missings but k.A. are in fact missings, we should recode them
p2008_descriptive$hp_altg3<-replace(p2008_descriptive$hp_altg3,p2008_descriptive$hp_altg3=="k.A.", NA)

summary(p2008_descriptive$hp_altg3) 
table(is.na(p2008_descriptive$hp_altg3)==T) #112 NAs

save(p2008_descriptive, file="p2008_descriptive.Rdata")

#end student task
#---------



#------------------------------------------------------------
#Filter check (its mainly about checking sample sizes)
#p0412_x: the data documentation documents 4 filters

#a) 1st Filter applies to all accessibility questions : adults from 14 years on, 
#without representative only; baseline sample only
#that means no people below 14 and no cases with proxy interviews/representatives 
#should have answered that question
#variable for checking: int_typ9: Form of the personal/trip interview (9 types)
#valid cases for int_typ9 should be only for values: 
#1 (1 = 'Adult > 13 years (individual) with trip protocol') ,
#6 (6 = 'Adult > 13 years (individual) without trip protocol (Reporting period <= 3 Tage/ out of the country)' and
#8 (8 = 'Adult > 13 years (individual) without trip protocol (Reporting period > 3 days)')

with(p2008_descriptive,table(p0412_1,int_typ9))

#Result o.k.  

#---------
save(p2008_descriptive, file="p2008_descriptive.Rdata")

#---------
#b) 2nd Filter applies to p0412_3: Accessibility of school by bicycle
#should only be valid for hp_beruf = 2 and age<18: 
#one could use one of the ordinal age variable that has a break between 17 and 18 in its categories
#that would be  hp_altg1 or hp_altg3 ; here  p0412_3 should only be valid for values 1 to 4
#(one could also recode hp_alter into 2 categories, but you should try to make us of the data/information
#that is provided. That saves time and effort!)
#calculate 3 contingency table  with hp_beruf  and hp_altg1

str(p2008_descriptive$p0412_3) #
summary(p2008_descriptive$p0412_3)

with(p2008_descriptive,table(p0412_3,hp_beruf,hp_altg1))

#code plan hp_altg1:
#1 = '0 - 5 years', 2 = '6 - 9', 3 = '10 - 13', 4 = '14 - 17', 5 = '18 - 24'
#6 = '25 - 44', 7 = '45 - 59', 8 = '60 - 64', 9 = '65 and older'

#Result o.k.  

#---------
save(p2008_descriptive, file="p2008_descriptive.Rdata")

#there are 24 cases in the category 18-24 year
#that suggests that the filter may need be interpreted as age =< 18
#But there is no ordinal age variable with a category break between 18 and 19
#thus we need to recode the metric age variable into a new variable with categories suitable for our purpose
#than run contingency table again

#---------
#create a new variable hp_altg4:
p2008_descriptive<-transform(p2008_descriptive,hp_altg4=0)
str(p2008_descriptive$hp_altg4) #num [1:60713] 0 0 0 0 0 0 0 0 0 0 ...
#change it into a factor variable
p2008_descriptive$hp_altg4<-as.factor(p2008_descriptive$hp_altg4)
str(p2008_descriptive$hp_altg4) #Factor w/ 1 level "0": 1 1 1 1 1 1 1 1 1 1 ...
#assign the levels of your choice
levels(p2008_descriptive$hp_altg4)<-c("<17","<18","<19",">=19")
str(p2008_descriptive$hp_altg4) #Factor w/ 4 levels "<17","<18","<19",..: 1 1 1 1 1 1 1 1 1 1 ..
p2008_descriptive$hp_altg4<-replace(p2008_descriptive$hp_altg4,p2008_descriptive$hp_alter<17,"<17")
p2008_descriptive$hp_altg4<-replace(p2008_descriptive$hp_altg4,p2008_descriptive$hp_alter<18 & p2008_descriptive$hp_alter>=17,"<18")
p2008_descriptive$hp_altg4<-replace(p2008_descriptive$hp_altg4,p2008_descriptive$hp_alter<19 & p2008_descriptive$hp_alter>=18,"<19")
p2008_descriptive$hp_altg4<-replace(p2008_descriptive$hp_altg4,p2008_descriptive$hp_alter>=19,">=19")

with(p2008_descriptive,table(hp_altg4,hp_alter))

#compute the contingency tables again
with(p2008_descriptive,table(p0412_3,hp_beruf,hp_altg4))

#Result:
#Group 1 (lower 17) = most cases
#Group 2 (17) = many cases
#Group 3 (18) = 22 cases; our assumption was mostly correct, but
#Group 4 (>=19)  = still 2 cases 
#apparently there are 2 people that are pupils and above 19
#Decision what to do with them based on RQ : here only few cases no systematic distortion in the data, thus no Problem, leave them in

#---------
save(p2008_descriptive, file="p2008_descriptive.Rdata")

#---------


#---------
#Student task: check the 3rd and 4th Filter as well

#---------
#c) 3rd filter applies to accessibility work: p0412_1 (by bicycle)
#should be only valid for hp_beruf=1 ("ja") 
#cross tabulation for accessibilty of workplace for car, PT and bicycle  

with(p2008_descriptive,table(p0412_1,hp_beruf))

#Results: o.k.
#p0412_1 has hp_beruf = 1 as the only value
#p0412_1 x hp_beruf  valid cases correspond with the number of p0412_1 valid cases from the range check

#---------
#d) 4th Filter applies to p0412_2: Accessibility of apprenticeship location 
#shoud only be valid for hp_bkat=4 (apprentice)
#hp_beruf: Are you currently employed?, hp_bkat: Type/extent of employment 

with(p2008_descriptive,table(p0412_2,hp_bkat))

#Result: o.k

#end student task
#---------

#---------
save(p2008_descriptive, file="p2008_descriptive.Rdata")

#------------------------------------------------------------
#Consistency check
#To be done if necessary.

#------------------------------------------------------------
#Task 2: Aggregating Data
#not necessary since all variables are collected per person (our unit of analysis)

#------------------------------------------------------------
#Task 3: Calculate new data
#the H1 states that the higher frequency of bicycle use the better accessibility for all modes
#so we need to create an accessibility by bicycle index over all destinations
#Problem: we have missing values, person may have no complete itemset

#from task 1:
#Results p0412_1, Accessibility of workplace location by bicycle:
#19089 valid cases, 41624 missing values, 18776 cases come from level 507: not employed

#from student task:
#Results p0412_2, Accessibility of apprenticeship location by bicycle:
#646 valid cases, 60067 missing values, 18776 cases with p0412_2=NA come from level 507: not employed, 
#14801 cases with p0412_2=NA come from 102: adult (proxy), #4461 cases with p0412_2=NA come from 105: child of age<10

#from student task:
#Results p0412_3, Accessibility of school by bicycle:
#1506 valid cases, 59207 missing values, 19827 cases with p0412_3=NA come from level 501: employed, 
#14801 cases with p0412_3=NA come from 102: adult (proxy),
#4461 cases with p0412_3=NA come from 105: child of age<10
#17216 cases with p0412_3=NA come from 512: adult, not employed

#from task 1:
#Results p0412_4, Accessibility of shops |businesses (daily shopping) by bicycle:
#38394 valid cases, 22319 missing values, 14801 cases with p0412_4=NA come from 102: adult (proxy)

#Are there cases with no missing values in all the four variables?:
#NO, reason:
#variables p0412_2 and p0412_3 require non-adults or non-employed adults, variable p0412_1 requires employed adults
#these are mutually exclusive sets, there is no intersection

#Which variables to include for our accessibility index? p0412_1 and p0412_4
test<-p2008_descriptive[is.na(p2008_descriptive[,31])==F & is.na(p2008_descriptive[,34])==F,c(31:34)]
dim(test)
#test has 19068 cases, this is okay for work

#Compute accessibility index, in new variable p0412, as the mean from p0412_1 and p0412_4:
#Command:rowMeans
test<-rowMeans(p2008_descriptive[,c(31,34)],na.rm=T)
#problem: no mean can be computed for factor variables

#create new variables p0412_1n,p0412_4n, from p0412_1,p0412_4 as numerical values:
p2008_descriptive<-transform(p2008_descriptive,p0412_1n=as.numeric(p2008_descriptive$p0412_1))
with(p2008_descriptive,table(p0412_1,p0412_1n))
p2008_descriptive<-transform(p2008_descriptive,p0412_4n=as.numeric(p2008_descriptive$p0412_4))
with(p2008_descriptive,table(p0412_4,p0412_4n))

#---------
save(p2008_descriptive, file="p2008_descriptive.Rdata")

names(p2008_descriptive) #p0412_1n,p0412_4n are in columns 152:153
names(p2008_descriptive)[153:154] #

#test the rowMeans command:
test<-rowMeans(p2008_descriptive[,153:154],na.rm=T)
test<-cbind(test,p2008_descriptive[,c(31:34,153:154)])
head(test)
test[1:100,]
#end test the rowMeans command

#create the new variable with the mean accessibility workplace/shopping in p2008_descriptive
p2008_descriptive<-transform(p2008_descriptive,p0412=rowMeans(p2008_descriptive[,153:154],na.rm=T))
#visual check:
p2008_descriptive[1:20,c(31:34,153:155)]

#Check: the new index variable should have the same range than p0412_x (min 1, max 6)
with(p2008_descriptive,table(p0412))
summary(p2008_descriptive$p0412) #
#O.k.

#---------
save(p2008_descriptive, file="p2008_descriptive.Rdata")

#------------------------------------------------------------
#Task 4: Combining data
#there is no need to do that, since we have all relevant variables in the person data file

#------------------------------------------------------------
#Task 5: Defining subsamples
#the hypothesis does not specifiy a certain subgroup / subsample 
#thus we will include all people with valid cases for IV and DV 
#that means for us we need a filter that identifies and filters our subsample of all valied cases 
#for p033 and p0412

#either with command subset or:
names(p2008_descriptive) #p033: variable 9, p0412: variable 155
p2008_descriptive1<-p2008_descriptive[is.na(p2008_descriptive$p033)==F & is.na(p2008_descriptive$p0412)==F,]
#19058 cases

summary(p2008_descriptive1$p033) #no NAs
summary(p2008_descriptive1$p0412) #no NAs

#---------
save(p2008_descriptive1, file="p2008_descriptive1.Rdata")


#------------------------------------------------------------
#DATA ANALYSIS
#1.Descriptive data analysis
#central tendency, disperion, distribution 


#---------
#IV  p033: Frequency of bicycle use
#scale: ordinal
#calculate central tendency (median), dispersion (range) , distribution (frequencies of value categories, 
#visual inspection by barplot )

str(p2008_descriptive1$p033n) #
summary(p2008_descriptive1$p033n) #
table(p2008_descriptive1$p033n) #

#Results: 
#Median = 3 (1-3 day per months)
#Range = min 1, max 6, that means we have values within the full range from frequent bicyclists 
#to no bicyclists
#distribution: 17.8% cycle daily; 22.4 % cycle 1-3 days a week, 17,9% cycle 1-3 days a months, 
#12.3% cycle less than monthly and 22.4% cycle never or almost never, 7% do not own a cycle
#no normal distribution, rather evenly distributed with decrases in the middle of the scale
#a slight tendency for extrem groups (1 and 5) could be identfied

#---------
#DV:  p0412 'Accessibility per bicycle workplace, shopping
#metric variable because of the convention that a scale or index that is composed of several 
#ordinal items can be regarded as metric scale 
#calculate: Descriptives with mean, variance and standard deviation, skew and curtosis

with(p2008_descriptive1,table(p0412))

par(mfrow=c(1,1))
barplot(table(p2008_descriptive1$p0412)) 

summary(p2008_descriptive1$p0412) #0 NAs
with(p2008_descriptive1,table(p0412))
#standard deviation
sd(p2008_descriptive1$p0412,na.rm=T) #1.228172

#---------
#test whether p0412 is normally distributed, first step: plot the data
#histogram
par(mfrow = c(1, 2))
with(p2008_descriptive1,hist(p0412,main="p0412"))
#for comparison: normally distributed data with the same mean and sd
x<-rnorm(60713, mean = mean(p2008_descriptive1$p0412,na.rm=T), sd = sd(p2008_descriptive1$p0412,na.rm=T))
hist(x,main="")   

#Whether or not this distribution can still be regarded as a normal distribution can be tested 
#e.g. with Kolmogorov-Smirnov-Test
#This test analyses whether or not the distribution of one variable corresponds with the characteristics 
#of a normal distribution

#use the mean and the sd from p0412:
mean(p2008_descriptive1$p0412) #
sd(p2008_descriptive1$p0412) #

y<-rnorm(19058,mean=mean(p2008_descriptive1$p0412),sd=sd(p2008_descriptive1$p0412))

ks.test(p2008_descriptive1$p0412,y) #p<1%

#if the test is not significant we can regard the values of p0412 as normally distributed
#Result: the test is significant, that means our the data of p0412 are NOT normally distributed

#---------
#hp_alter, age, we will need it for the lecture on inferential statistics
summary(p2008_descriptive1$hp_alter) #
with(p2008_descriptive1,table(hp_alter))
#standard deviation
sd(p2008_descriptive1$hp_alter,na.rm=T)

#Results:
#age: min=1, max = 93, mean=45.63, Standard deviation: 10.24, 

#barplot
par(mfrow=c(1,1))
barplot(table(p2008_descriptive1$hp_alter)) 

#histogram
par(mfrow = c(1, 2))
with(p2008_descriptive1,hist(hp_alter,main="hp_alter"))
#for comparison: normally distributed data with the same mean and sd
x<-rnorm(60713, mean = mean(p2008_descriptive1$hp_alter,na.rm=T), sd = sd(p2008_descriptive1$hp_alter,na.rm=T))
hist(x,main="")   

#or with kernel-density estimates:
?hist #look for parameters breaks and freq
?density #lok for ways how to deal with NAs
par(mfrow = c(1, 1))
with(p2008_descriptive1,{
  hist(hp_alter,breaks="FD",freq=F,main="hp_alter")
  lines(density(hp_alter,na.rm=T),lwd=2,col="red")
})

#---------
#Whether or not  the  distribution of hp_alter can still be regarded as a normal distribution 
#can be tested e.g. with Kolmogorov-Smirnov-Test
#This test analyses whether or not the distribution of one variable corresponds with the 
#characteristics of a normal distribution.

#ks.test(x, y, ...,alternative = c("two.sided", "less", "greater"),)
#x   a numeric vector of data values.
#y   either a numeric vector of data values, or a character string naming a cumulative 
#distribution function or an actual cumulative distribution function such as pnorm.

#generate y: a vector of random values from the normal distribution:
#rnorm(n, mean = 0, sd = 1)

#use the mean and the sd from hp_alter:
mean(p2008_descriptive1$hp_alter, na.rm=T) #
sd(p2008_descriptive1$hp_alter, na.rm=T) #

y<-rnorm(19058,mean=mean(p2008_descriptive1$hp_alter, na.rm=T),sd=sd(p2008_descriptive1$hp_alter, na.rm=T))

ks.test(p2008_descriptive1$hp_alter,y) #p<1%

#if the test is not significant we can regard the values of hp_alter as normally distributed
#Result: the test is significant, that means our the data of hp_alter is NOT normally distributed

#---------
save(p2008_descriptive1, file="p2008_descriptive1.Rdata")

#------------------------------------------------------------
#2. Inferential statistics
#H 1: The more often people use the bicycle the better the accessibility by bicycle is assessed 
#for workplace and shopping. 

#What are you testing for? 
#Relation between frequency of bicycle usage and assessment of accessibility by bike

#What type of data do you have?
#1 IV: p033: Frequency of bicycle use
#I DV: p0412: Accessibility per bicycle worksplace, shopping
#IV ordinal, DV metric
#DV not normal distributed

#Do you have related or unrelated data?
#IV and DV independent observations

#Statistical Tests:
#a) Correlation analysis
#does not only test for a relationship but also the intensity of the relationship as stated by the hypothesis
#there are a number of different correlation coefficients depending on scale level
#we have different scale levels for IV and DV, rule of thumb is to move downwards in scale level 
#or to use a coefficent that is developed for that special case
#in here we downgrade since no specific coefficient is available
#calculate:  Spearman's rank correlation coefficient (Spearmans Rho), one-tailed

#in R: 
#cor(x, y = NULL, use = "everything",method = c("pearson", "kendall", "spearman"))

summary(p2008_descriptive1$p033n) #0 NAs
summary(p2008_descriptive1$p0412) #0 NAs
cor(p2008_descriptive1$p033n,p2008_descriptive1$p0412,method = "spearman") #

#test the significance:
#cor.test(x, y,alternative = c("two.sided", "less", "greater"),
    #method = c("pearson", "kendall", "spearman"),conf.level = 0.95, ...)

cor.test(p2008_descriptive1$p033n,p2008_descriptive1$p0412,method = "spearman",alternative = "two.sided")

#Result: 
#a) Significance: highly significant result p<.01
#there is a significant relation between frequency of bicycle usage and assessment of accessibility 
#per bicycle worksplace, shopping
#b) Correlation coefficient: is positive, that means higher values in one variable are associated 
#with higher values in the other variable
#thus the higher value for for frequency of bicycle use the higher the values for the accessibility by bike index
#c) size of correlation coefficient: .27, interpretion according to classifications (rule of thumb): weak
#the relation gets higly significant because of the big sample size not because of the strenghts of the relationship

#to compare that lets also test for Kendalls Tau 

cor(p2008_descriptive1$p033n,p2008_descriptive1$p0412,method = "kendall") #
cor.test(p2008_descriptive1$p033n,p2008_descriptive1$p0412,method = "kendall",alternative = "two.sided")

#DISCUSSION
#see case study / ppt
 
#---------
save(p2008_descriptive, file="p2008_descriptive.Rdata")
save(p2008_descriptive1, file="p2008_descriptive1.Rdata")


|
