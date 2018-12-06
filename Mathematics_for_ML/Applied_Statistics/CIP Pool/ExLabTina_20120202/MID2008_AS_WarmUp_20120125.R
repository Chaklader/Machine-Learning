
#Applied Statistics in transport, WS2011/12

#NUMBER 1
#Warm up lab session, case study MID2008, first class of guest lecture Tina Gehlert
#Goal: recall r-commands from first lab sessions in the beginning of the semester

setwd("U:\\")

#Data sets in the folder ExLab5_MID2008_Descriptive\\:
#p2008extendedASOriginal.Rdata: the same as p2008 but with more variables and some coded variables, prepared by Regine Gerike for the course Applied Statistics 
#p2008extendedAS.Rdata: the same as p2008extendedASOriginal but for your work

#--------------------------------------------------------------
#Notation:
#IV: independent variable
#DV: dependent variable
#--------------------------------------------------------------
 
#------------------------------------------------------------
#create the copy of the data set for your work:
load("L:\\LS_Verkehrstechnik\\AppliedStatistics\\ExLabTina_20120202\\p2008extendedASOriginal.Rdata")
p2008extendedAS<-p2008extendedASOriginal
save(p2008extendedAS, file="p2008extendedAS.Rdata")
#load("ExLabTina_MID2008_GuestLecture\\p2008extendedAS.Rdata")
rm(p2008extendedASOriginal)
ls()

#------------------------------------------------------------
#have a first look at your dataset
str(p2008extendedAS)
names(p2008extendedAS)
head(p2008extendedAS)
p2008extendedAS[1:5,c(1:4,31:34)]


#------------------------------------------------------------
#Data input and preparation

#check relevant variables, recode them to factor variables, insert missing values, basis: codeplan

#p033: Frequency of bicycle use
str(p2008extendedAS$p033) #Factor w/ 14 levels "Tägl","1bis3Woche",..: 3 1 3 2 10 3 2 1 5 6 ...
summary(p2008extendedAS$p033) 
table(p2008extendedAS$p033) #for factor variables similar to summary but without missing values
table(is.na(p2008extendedAS$p033)==T) #check for missing values

#no missings but Verweigert, WeißNicht, 102:109 are in fact missings, we should recode them
p2008extendedAS$p033<-replace(p2008extendedAS$p033,p2008extendedAS$p033=="Verweigert" 
    | p2008extendedAS$p033=="WeißNicht" | p2008extendedAS$p033=="102"
    | p2008extendedAS$p033=="103" | p2008extendedAS$p033=="104"
    | p2008extendedAS$p033=="105" | p2008extendedAS$p033=="107"
    | p2008extendedAS$p033=="109", NA)

str(p2008extendedAS$p033) #Factor w/ 14 levels "Tägl","1bis3Woche",..: 3 1 3 2 10 3 2 1 5 6 ...
summary(p2008extendedAS$p033) 
table(p2008extendedAS$p033) #for factor variables similar to summary but without missing values
table(is.na(p2008extendedAS$p033)==T) #check for missing values

#Results:
#p033 : min max = all factor levels, that corresponds with valid range from codebook
#38577 valid cases, 22136 (defined!) missing values, no undefined missings

#Levels with NAs in p033 are annoying
str(p2008extendedAS$p033) #Factor w/ 14 levels "Tägl","1bis3Woche",..: 3 1 3 2 NA 3 2 1 5 6 ...
levels(p2008extendedAS$p033)
#summarize levels with only missing values
levels(p2008extendedAS$p033)[c(7:14)] <- "HabeKeinRad"
summary(p2008extendedAS$p033)

#---------
save(p2008extendedAS, file="p2008extendedAS.Rdata")

#---------
#create a new variable, p033n, p033 as numeric value
p2008extendedAS<-transform(p2008extendedAS,p033n=as.numeric(p2008extendedAS$p033))

#---------
#Two-dim contingency table
with(p2008extendedAS,table(p033,p033n))

summary(p2008extendedAS$p033n) #
table(p2008extendedAS$p033n) #

(dim<-dim(p2008extendedAS[is.na(p2008extendedAS$p033n)==F,]))
dim[1]
table(p2008extendedAS$p033n)/dim[1]*100 #relative frequency with dim[1] being the number of cases with no NA


#---------
save(p2008extendedAS, file="p2008extendedAS.Rdata")

#---------
#Select data
names(p2008extendedAS) #p033 in column 9, columns 31:34: accessibility of different destinations by bicycle
names(p2008extendedAS)[c(9,31:34)] #
p033_1<-p2008extendedAS[is.na(p2008extendedAS[,9])==F & p2008extendedAS[,9]=="Tägl",c(9,31:34)]
p033_2<-p2008extendedAS[is.na(p2008extendedAS[,9])==F & p2008extendedAS[,9]=="1bis3Woche",c(9,31:34)]

#2nd alternative: command subset
p033_3<-subset(p2008extendedAS, is.na(p033)==F & p033 == "1bis3Woche", select = c(9,31:34))

#3rd alternative: command split
p033_4<-split(p2008extendedAS[,c(9,31:34)],p2008extendedAS$p033)
str(p033_4)
head(p033_4$Tägl)
p033_4$Tägl[1:5,]

#---------
#Command: rowMeans, colMeans, rowSums, colSums
#Compute the mean age, variable hp_alter
names(p2008extendedAS) #17 hp_alter, 18 hp_altg1, 126 NoTripsPerson, 127:134 Number of trips per purpose
str(p2008extendedAS$hp_alter) #int [1:60713] 47 52 58 37 12 46 44 18 16 25 ...
summary(p2008extendedAS$hp_alter) 
#   Min. 1st Qu.  Median    Mean 3rd Qu.    Max. 
#   0.00   23.00   47.00   45.33   61.00  999.00 
table(p2008extendedAS$hp_alter) #
table(is.na(p2008extendedAS$hp_alter)==T) #check for missing values

#no missings but 994:999 are in fact missings, we should recode them
p2008extendedAS$hp_alter<-replace(p2008extendedAS$hp_alter,p2008extendedAS$hp_alter=="994"
      | p2008extendedAS$hp_alter=="997" | p2008extendedAS$hp_alter=="998"
      | p2008extendedAS$hp_alter=="999", NA)

summary(p2008extendedAS$hp_alter) 
table(is.na(p2008extendedAS$hp_alter)==T) #112 NAs

names(p2008extendedAS)[c(17,126,127:134)]
(test<-colMeans(p2008extendedAS[,c(17,126,127:134)],na.rm=T))

#---------
#mean of a num variable per factor level of a factor variable
summary(p2008extendedAS$p033) #!There are NAs
summary(p2008extendedAS$NoTripsPerson)
with(p2008extendedAS,tapply(NoTripsPerson,p033,mean,na.rm=T))
tapply(p2008extendedAS$NoTripsPerson,p2008extendedAS$p033, mean, na.rm=T)
with(p2008extendedAS[is.na(p2008extendedAS$p033)==F & is.na(p2008extendedAS$NoTripsPerson)==F,],tapply(NoTripsPerson,p033,mean,na.rm=T))

#of for more factor variables: hp_altg1
with(p2008extendedAS,tapply(NoTripsPerson,list(p033,hp_altg1),mean,na.rm=T))


#---------
#DATA ANALYSIS
#1.Descriptive data analysis
#central tendency, disperion, distribution 

#Sample statistics 
#age / gender

with(p2008extendedAS,table(p033n))
summary(p2008extendedAS$p033n)

par(mfrow=c(1,1))
barplot(table(p2008extendedAS$p033n)) 

#standard deviation
sd(p2008extendedAS$p033n,na.rm=T)
#skewness and kurtosis
library(fBasics) #if necessary: install.packages("fBasics")
skewness(p2008extendedAS$p033n, na.rm=T) #0.06633487
kurtosis(p2008extendedAS$p033n, na.rm=T) #-1.406018

with(p2008extendedAS,table(is.na(p033n)==T))

 
#---------
save(p2008extendedAS, file="p2008extendedAS.Rdata")


#------------------------------------------------------------
#Student tasks
#------------------------------------------------------------
#1. Copy the data.frame p2008extendedAS to a new data.frame with name test
#2. Save test to your working directory
#3. List columns 1:5 from rows 30:35, data: test
#4. List all columns from rows 30:35, data: test
#5. write all rows from columns 31:34 into a new data.frame, data: test1
#6. List the names of test
#7. Check the variable scales for test
#8. Check the number of missing values in the variable p0412_2. Insert missing values if necessary (command: replace), data: test
#9. Summarize the levels that contain only missing values in variable p0412_2 (command levels), data: test
#10. Create a contingency table for p0412_2 (command: table), data: test
#11. Create a two-dim contingency table for p0412_2 and hp_beruf (command: table), data: test
#12. Create a new data.frame from test that contains only columns 1:5 from rows 30:35
#13. Change the format of some variables of your choice (e.g. factor --> numeric variable: as.numeric, numeric --> factor: as.factor)
#14. Add a new column with name p0412_2n (command transform), that is the numeric value from p0412_2, data: test
#15. Create a new data.frame that contains no cases with missing values in the variable p0412_2, data: test
#------------------------------------------------------------



#---------
#Only if time is left: Kolmogorov-Smirnov-Test
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
mean(p2008extendedAS$hp_alter, na.rm=T) #
sd(p2008extendedAS$hp_alter, na.rm=T) #

y<-rnorm(60713,mean=mean(p2008extendedAS$hp_alter, na.rm=T),sd=sd(p2008extendedAS$hp_alter, na.rm=T))

ks.test(p2008extendedAS$hp_alter,y) #p<1%

#if the test is not significant we can regard the values of hp_alter as normally distributed
#Result: the test is significant, that means our the data of our index are NOT normally distributed


|
