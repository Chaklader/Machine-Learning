
#for later starts:
setwd("c:\\Users\\gerike\\Documents\\Lacie\\Daten\\MiD2008\\")
load("Auswertung\\p2008extended.Rdata") 
load("c:\\Users\\gerike\\Documents\\Lacie\\Lehre\\AppliedStatisticsInTransport\\WS11_12\\ExLab3_DataInputPreparation\\p2008.Rdata")

#--------------------------------------------------------------
#--------------------------------------------------------------
#for 29.11. Notwendigkeit einer Einführung von missing values mit der stetigen Variable Alter erklären


#loading and preparation of MID2008 for Applied Statistics in Transport 
#newly created variables and original MID2008 variables are described in "MiD2008EnglCodeplan20111114extended.xlsx" 

setwd("c:\\Users\\gerike\\Documents\\Lacie\\Daten\\MiD2008\\")
getwd()

#--------------------------------------------------------------
#--------------------------------------------------------------
#Personal Data
p2008original <- read.table("SPSS_MiD2008\\SPSS_Public Use File\\MiD2008_PUF_Personen.dat", header=T,sep="\t")
head(p2008original)
str(p2008original) #60713 obs. of  124 variables, most of the variables are integer variables
dim(p2008original) #
isna<-apply(apply(p2008original,2,is.na),2,sum)    #Number of NAs for all variables
table(isna)  #or with only one command apply(apply(wmuc2002,2,is.na),2,sum)
#   0
#  124 #no NA
table(complete.cases(p2008original)) #TRUE 60713

#-------------
#check your primary keys:
?duplicated #Determine Duplicate Elements
table(duplicated(p2008[,1:2])) #FALSE: 60713
table(duplicated(p2008[,1])) #FALSE: 25922,  TRUE: 34791

#-------------
#Save original data file before starting the work:
save(p2008original, file="c:\\Users\\gerike\\Documents\\Lacie\\Lehre\\AppliedStatisticsInTransport\\WS11_12\\ExLab3_DataInputPreparation\\p2008original.Rdata")
load("c:\\Users\\gerike\\Documents\\Lacie\\Lehre\\AppliedStatisticsInTransport\\WS11_12\\ExLab3_DataInputPreparation\\p2008original.Rdata")

#Create your data file for the analyses
p2008<-p2008original #change the name
save(p2008, file="c:\\Users\\gerike\\Documents\\Lacie\\Lehre\\AppliedStatisticsInTransport\\WS11_12\\ExLab3_DataInputPreparation\\p2008.Rdata")
#load("c:\\Users\\gerike\\Documents\\Lacie\\Lehre\\AppliedStatisticsInTransport\\WS11_12\\ExLab3_DataInputPreparation\\p2008.Rdata")

rm(p2008original)
ls()  #"p2008"

#-------------
#change the format of the variables, example p01_1
with(p2008,table(p01_1)) #Wie oft als Fahrer über Auto verfügen, How often is the car available for use?
p2008$p01_1 <- as.factor(p2008$p01_1)
levels(p2008$p01_1) <-c("Jederzeit","Gelegentlich","GarNicht","KeinFührerschein","Verweigert","WeißNicht","102","103","104","105","107","109","110")  #nicht besetzt
with(p2008,table(p01_1)) #102: 14801
str(p2008[1:10])
levels(p2008$p01_1)
#Coding of missing values
p2008$p01_1 <- replace(p2008$p01_1, p2008$p01_1 == "102", NA)
with(p2008,table(p01_1))
summary(p2008$p01_1) #NA: 14801
#for all missing values variables: | or
p2008$p01_1 <- replace(p2008$p01_1, p2008$p01_1 == "102" | p2008$p01_1 == "103" |
  p2008$p01_1 == "104" |p2008$p01_1 == "105" |p2008$p01_1 == "107" |
  p2008$p01_1 == "109" |p2008$p01_1 == "110" |p2008$p01_1 == "Verweigert"  |
  p2008$p01_1 == "WeißNicht", NA)
with(p2008,table(p01_1))
summary(p2008$p01_1) #NA: 23303

save(p2008, file="c:\\Users\\gerike\\Documents\\Lacie\\Lehre\\AppliedStatisticsInTransport\\WS11_12\\ExLab3_DataInputPreparation\\p2008.Rdata")


#-------------
#change the following variables into factor variables: 
#create hp_altg1 from hp_alter

str(p2008[16:19])
with(p2008,table(hp_alter))
#code missing values:
p2008$hp_alter <- replace(p2008$hp_alter, p2008$hp_alter == "994" | 
  p2008$hp_alter == "997" |p2008$hp_alter == "998" |p2008$hp_alter == "999", NA)
summary(p2008$hp_alter) #NA: 112
mean(p2008$hp_alter) #NA
?mean
mean(p2008$hp_alter, na.rm = TRUE) #44

#look at the data
hist(p2008$hp_alter)
par(mfrow = c(2, 2))
hist(p2008$hp_alter, breaks = 5, main = "breaks=5")
hist(p2008$hp_alter, breaks = 10, main = "breaks=10")
hist(p2008$hp_alter, breaks = 20, main = "breaks=20")
hist(p2008$hp_alter, breaks = 30, main = "breaks=30")

#We use "cut"" for converting the numeric to factors:
?cut #intervals should be closed on the right and open on the left

hp_altg1_checked <- cut(p2008$hp_alter, breaks = c(0, 6, 10, 14, 18, 25, 45, 60, 65, 1000), right=FALSE)
table(hp_altg1_checked)
#names are confusing, we change them:
hp_altg1_checked <- cut(p2008$hp_alter, breaks = c(0, 6, 10, 14, 18, 25, 45, 60, 65, 1000), 
    right=FALSE, labels = c("0-5","6-9","10-13","14-17","18-24","25-44","45-59","60-64",">=65"))
table(hp_altg1_checked)
hist(hp_altg1_checked) #only for numeric variables
par(mfrow = c(1, 1))
barplot(table(hp_altg1_checked), main = "Age, Grouped")


n<-length(hp_altg1_checked)
table(hp_altg1_checked)/n*100 #relative frequencies as percentages

#combine the new with the original variable hp_altg1
age_group_compare<-cbind(p2008$hp_altg1,hp_altg1_checked)
head(age_group_compare)
table(age_group_compare[,1]-age_group_compare[,2]) #0 for 60601 obs., 60713-60601=112
summary(age_group_compare) #NA: 112

#there are no differences between our variable and the original one
#remove the variables you do not need anymore:
rm(age_group_compare,hp_altg1_checked)
ls()

#-------------
#Range checks
#Aim: 
#to get familiar with the data set, 
#to check for data enty mistakes
#to check for correspondence between data set and questionnaires

#variables.  accessibility variables
#calculated: frequncies, mininum, maximum, median, number of valid cases
summary(p2008$wege1)
#Coding of missing values
p2008$wege1 <- replace(p2008$wege1, p2008$wege1 > 98, NA)
summary(p2008$wege1) #NA: 3118

#-------------
#Filter checks
#See MiD2008_Fragebogenmaster_PW-Interview.pdf, page 7
#see 2011-11-10_MiD2008_Information_en.docx 
#accessibility work: p0412_1 (by bicycle), p0413_1 (by pt), p0414_1 (by car)
#should be only valid for hp_beruf=1 ("ja")
table(p2008$p0412_1,p2008$hp_beruf)
#true: we have only missing values for p0412_1 in hp_beruf=2 to 9
with(p2008,table(hp_beruf)) #
p2008$hp_beruf <- as.factor(p2008$hp_beruf)
levels(p2008$hp_beruf) <-c("Ja","Nein","Verweigert","WeißNicht","k.A.")  #
with(p2008,table(hp_beruf)) 

#insert missing values
p2008$hp_beruf <- replace(p2008$hp_beruf, p2008$hp_beruf == "Verweigert" | 
  p2008$hp_beruf == "WeißNicht" |  p2008$hp_beruf == "k.A.", NA)
with(p2008,table(hp_beruf))
summary(p2008$hp_beruf) #NA: 361

with(p2008,table(p0412_1)) #
p2008$p0412_1 <- as.factor(p2008$p0412_1)
levels(p2008$p0412_1) <-c("SehrGut","Gut","Eingerm","Schlecht","SehrSchlecht","GarNicht","Verweigert","WeißNicht","102","103","104","105","107","109","502","506","507","514")  #
with(p2008,table(p0412_1)) 
#insert missing values
p2008$p0412_1 <- replace(p2008$p0412_1, p2008$p0412_1 == "Verweigert" | 
  p2008$p0412_1 == "WeißNicht" |  p2008$p0412_1 == "k.A." |
  p2008$p0412_1 == "102" |p2008$p0412_1 == "103" |
  p2008$p0412_1 == "104" |p2008$p0412_1 == "105" |
  p2008$p0412_1 == "107" |p2008$p0412_1 == "109" |
  p2008$p0412_1 == "502" |p2008$p0412_1 == "506" |
  p2008$p0412_1 == "507" |p2008$p0412_1 == "514", NA)
with(p2008,table(p0412_1))
summary(p2008$p0412_1) #NA: 41624

table(p2008$p0412_1,p2008$hp_beruf)
#Now it is even more clear.

#-------------
#student task: 
#check the other variables: p0413_1 (by pt), p0414_1 (by car)
#check accessibility vocational training, school
#suggestions for additional checks:
#check the number of valid cases for the different age variables:
#Same number of missing values for all age variables?
#cross check plausibility, e.g.
table(p2008$p0414_3, p2008$hp_beruf, p2008$hp_altg1)
#no accessibility for school kids of age<14, because they proxies were not asked those questions:
*age ranges from 14 to 17 and 18 to 24 years, where does that come from?
* restriction to 14 and above comes from the survey design
*Auszug aus: E:\MiD2008\Dokumentation\Methodenbericht\MiD2008_Methodenbericht.pdf 
*also in documented in the Interview guide as filter for p04xx

*Die Erhebungen auf der Personen-Wege-Ebene umfassten
in den unterschiedlichen Interviewvarianten (selbst
antwortende bzw. stellvertretend antwortende Kinder unter
14 Jahre bzw. Erwachsene) jeweils ein einheitliches Set
an Basisvariablen. Zusätzlich wurden einige personenbezogene
Fragen (zumeist subjektive Einschätzungen), die
weiterführende Analysen ermöglichen, an selbst antwortende
Personen ab 14 Jahre gestellt. Da davon ausgegangen
wurde, dass Fragen der subjektiven Einschätzung nur von
der betreffenden Person selbst korrekt beantwortet werden
können (wie beispielsweise die Anzahl der in den letzten
drei Monaten unternommenen Reisen mit mindestens einer
auswärtigen Übernachtung), wurden diese Fragen nicht
durch stellvertretend antwortende Personen erhoben. 

#Conclusion: Checks are very important, do them only for the variables you need,
#otherwise you get lost.

#-------------
#Outlook:

#-------------
#Exploratory analyses
#for commands look at the mfund.data example, AS_DescriptiveStatistics_mfundData.r 
#We will do this together next week.


#-------------
#Compute new variables
#We will do this together next week.

save(p2008, file="c:\\Users\\gerike\\Documents\\Lacie\\Lehre\\AppliedStatisticsInTransport\\WS11_12\\ExLab3_DataInputPreparation\\p2008.Rdata")
load("c:\\Users\\gerike\\Documents\\Lacie\\Lehre\\AppliedStatisticsInTransport\\WS11_12\\ExLab3_DataInputPreparation\\p2008.Rdata")

