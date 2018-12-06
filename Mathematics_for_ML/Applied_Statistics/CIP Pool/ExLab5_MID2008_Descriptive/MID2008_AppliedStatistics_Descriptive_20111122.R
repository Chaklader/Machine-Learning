

setwd("u:\\")

#Data sets in the folder ExLab5_MID2008_Descriptive\\:
#p2008extendedASOriginal.Rdata: the same as p2008 but with more variables and some coded variables, prepared by Regine Gerike for the course Applied Statistics 
#p2008extendedAS.Rdata: the same as p2008extendedASOriginal but for your work

#load("p2008extendedASOriginal.Rdata")

#--------------------------------------------------------------
#--------------------------------------------------------------
 
#create the copy of the data set for your work:
load("L:\\LS_Verkehrstechnik\\AppliedStatistics\\ExLab5_MID2008_Descriptive\\p2008extendedASOriginal.Rdata")
p2008extendedAS<-p2008extendedASOriginal
save(p2008extendedAS, file="p2008extendedAS.Rdata")
#load("p2008extendedAS.Rdata")
rm(p2008extendedASOriginal)
ls()

#------------------------------------------------------------
#Descriptive analysis: 
#simple summaries (that's why Descriptive) about the sample 
#Together with simple graphics analysis, they form the basis of quantitative analysis of data.

#Three main parts: 
#1. the central tendency; 
#2.	the dispersion and range
#3.	the position
#4. the shape/distribution; 

#Descriptive analysis for person data file

#1. Accessibility (subjective assessment), variables:
p0411_3  Accessibility of school by foot
p0411_4  Accessibility of shops |businesses (daily shopping) by foot
p0412_1  Accessibility of workplace by bicycle
p0412_2  Accessibility of apprenticeship location by bicycle
p0412_3  Accessibility of school by bicycle
p0412_4  Accessibility of shops |businesses (daily shopping) by bicycle
p0413_1  Accessibility of workplace by public transportation
p0413_2  Accessibility of apprenticeship location by public transportation
p0413_3  Accessibility of school by public transportation
p0413_4  Accessibility of shops |businesses (daily shopping) by public transportation
p0413    Accessiblity of destinations with public transportation
p0414_1  Accessibility of workplace by car
p0414_2  Accessibility of apprenticeship location by car
p0414_3  Accessibility of school by car
p0414_4  Accessibility of shops |businesses (daily shopping) by car


#Example: Accessibility with the car 
#calculate: frequencies

with(p2008extendedAS,table(p0414_1)) #Accessibility of workplace by car
summary(p2008extendedAS$p0414_1)
p2008extendedAS$p0414_1 <- replace(p2008extendedAS$p0414_1, p2008extendedAS$p0414_1 == "Verweigert" |
  p2008extendedAS$p0414_1 == "WeißNicht" | 
  p2008extendedAS$p0414_1 == "102" |p2008extendedAS$p0414_1 == "103" |
  p2008extendedAS$p0414_1 == "104" |p2008extendedAS$p0414_1 == "105" |
  p2008extendedAS$p0414_1 == "107" |p2008extendedAS$p0414_1 == "109" |
  p2008extendedAS$p0414_1 == "502" |p2008extendedAS$p0414_1 == "503" |
  p2008extendedAS$p0414_1 == "506" |p2008extendedAS$p0414_1 == "507" |
  p2008extendedAS$p0414_1 == "514", NA)
summary(p2008extendedAS$p0414_1) #NA: 41643

#Accessibility of apprenticeship location by car
with(p2008extendedAS,table(p0414_2))
summary(p2008extendedAS$p0414_2) #factor variable, but missing values are not coded
p2008extendedAS$p0414_2 <- replace(p2008extendedAS$p0414_2, p2008extendedAS$p0414_2 == "WeißNicht" | 
  p2008extendedAS$p0414_2 == "102" |p2008extendedAS$p0414_2 == "103" |
  p2008extendedAS$p0414_2 == "104" |p2008extendedAS$p0414_2 == "105" |
  p2008extendedAS$p0414_2 == "107" |p2008extendedAS$p0414_2 == "109" |
  p2008extendedAS$p0414_2 == "504" |p2008extendedAS$p0414_2 == "505" |
  p2008extendedAS$p0414_2 == "506" |p2008extendedAS$p0414_2 == "507"|p2008extendedAS$p0414_2 == "514", NA)
summary(p2008extendedAS$p0414_2) #60103 NA

summary(p2008extendedAS$p0414_3) #Accessibility of school by car
p2008extendedAS$p0414_3 <- replace(p2008extendedAS$p0414_3,  
  p2008extendedAS$p0414_3 == "102" |p2008extendedAS$p0414_3 == "103" |
  p2008extendedAS$p0414_3 == "104" |p2008extendedAS$p0414_3 == "105" |
  p2008extendedAS$p0414_3 == "107" |p2008extendedAS$p0414_3 == "109" |
  p2008extendedAS$p0414_3 == "501" |p2008extendedAS$p0414_3 == "508" |
  p2008extendedAS$p0414_3 == "509" |p2008extendedAS$p0414_3 == "510" |
  p2008extendedAS$p0414_3 == "512" |p2008extendedAS$p0414_3 == "513"|p2008extendedAS$p0414_3 == "515", NA)
summary(p2008extendedAS$p0414_3) #60332 NA
with(p2008extendedAS,table(p0414_3))

summary(p2008extendedAS$p0414_4) #Accessibility of shops |businesses (daily shopping) by car
p2008extendedAS$p0414_4 <- replace(p2008extendedAS$p0414_4, p2008extendedAS$p0414_4 == "Verweigert" | 
  p2008extendedAS$p0414_4 == "WeißNicht" |
  p2008extendedAS$p0414_4 == "102" |p2008extendedAS$p0414_4 == "103" |
  p2008extendedAS$p0414_4 == "104" |p2008extendedAS$p0414_4 == "105" |
  p2008extendedAS$p0414_4 == "107" |p2008extendedAS$p0414_4 == "109"|p2008extendedAS$p0414_4 == "110", NA)
summary(p2008extendedAS$p0414_4) #23439 NA
with(p2008extendedAS,table(p0414_4))

par(mfrow=c(1,1))
barplot(table(p2008extendedAS$p0414_1)) #Accessibility of workplace by car
p0414_1<-p2008extendedAS$p0414_1
levels(p0414_1)
levels(p0414_1)[c(6:19)] <- "GarNicht"
summary(p0414_1)
barplot(table(p0414_1))
#p0414_1<-na.exclude(p0414_1)

barplot(table(p2008extendedAS$p0414_2)) #Accessibility of apprenticeship location by car
p0414_2<-p2008extendedAS$p0414_2
summary(p0414_2)
levels(p0414_2)
levels(p0414_2)[c(6:18)] <- "GarNicht"
barplot(table(p0414_2))

barplot(table(p2008extendedAS$p0414_3)) #Accessibility of school by car
p0414_3<-p2008extendedAS$p0414_3
summary(p0414_3)
levels(p0414_3)
levels(p0414_3)[c(6:19)] <- "GarNicht"
barplot(table(p0414_3))

barplot(table(p2008extendedAS$p0414_4)) #Accessibility of shops |businesses (daily shopping) by car
p0414_4<-p2008extendedAS$p0414_4
summary(p0414_4)
levels(p0414_4)
levels(p0414_4)[c(6:15)] <- "GarNicht"
barplot(table(p0414_4))

par(mfrow=c(2,2))
barplot(table(p0414_1),main="workplace") #Accessibility of workplace by car
barplot(table(p0414_2),main="apprenticeship",cex.axis=0.5,cex.names=0.5, cex.main=0.5) #Accessibility of apprenticeship location by car
barplot(table(p0414_3),main="school",cex.axis=0.5,cex.names=0.5, cex.main=0.5) #Accessibility of school by car
barplot(table(p0414_4),main="shops",cex.axis=0.5,cex.names=0.5, cex.main=0.5) #Accessibility of shops |businesses (daily shopping) by car

#optional: set graphic parameter: e.g. ",cex.axis=0.5,cex.names=0.5, cex.main=0.5" (check with ?barplot)

#Results:
#range: there are values from 1 to 5 
#But median = 1 for all trip types, inspection of frequencies shows that 
#over 60% state that accessibiltiy by car is very good for all trip types
#hence the distribution is positive or right skewed

#The descriptive analysis could also be done for relevant subgroups 
#e.g. accessibility by car depending on gender
#calculate: 2x5 contingency table (later on we can test for equal frequency 
#distribution between men and women (50:50 chance), Chi2 test)

summary(p2008extendedAS$hp_sex)
p2008extendedAS$hp_sex <- replace(p2008extendedAS$hp_sex, p2008extendedAS$hp_sex == "k.A.", NA)
summary(p2008extendedAS$hp_sex) #4 NA
hp_sex<-p2008extendedAS$hp_sex
summary(hp_sex)
levels(hp_sex)
levels(hp_sex)[3] <- "w"
barplot(table(hp_sex))

table(hp_sex,p0414_1)
#      p0414_1
#hp_sex SehrGut  Gut Eingerm Schlecht SehrSchlecht GarNicht
#     m    5300 2878     394      134           50      485
#     w    6220 2556     311      175           61      506>

#more women than man indicate 1 = very good accessibility of workplace by car
#more men than women indicate 2 = good and 3= reasonable accessibilty  

#Student task: Accessibility  by foot, bicycle, should be less homogeneous


save(p2008extendedAS, file="ExLab5_MID2008_Descriptive\\p2008extendedAS.Rdata")


#------------------------------------------------------------------------
#More examples:

#Accessibility of apprenticeship location by bicycle
with(p2008extended,table(p0412_2))
summary(p2008extended$p0412_2) #factor variable, but missing values are not coded
p2008extended$p0412_2 <- replace(p2008extended$p0412_2, p2008extended$p0412_2 == "WeißNicht" | 
  p2008extended$p0412_2 == "102" |p2008extended$p0412_2 == "103" |
  p2008extended$p0412_2 == "104" |p2008extended$p0412_2 == "105" |
  p2008extended$p0412_2 == "107" |p2008extended$p0412_2 == "109" |
  p2008extended$p0412_2 == "505" |p2008extended$p0412_2 == "506" |
  p2008extended$p0412_2 == "507" |p2008extended$p0412_2 == "514", NA)
summary(p2008extended$p0412_2) #22101 NA

summary(p2008extended$p0412_3) #Accessibility of school by bicycle
p2008extended$p0412_3 <- replace(p2008extended$p0412_3, p2008extended$p0412_3 == "WeißNicht" | 
  p2008extended$p0412_3 == "102" |p2008extended$p0412_3 == "103" |
  p2008extended$p0412_3 == "104" |p2008extended$p0412_3 == "105" |
  p2008extended$p0412_3 == "107" |p2008extended$p0412_3 == "109" |
  p2008extended$p0412_3 == "501" |p2008extended$p0412_3 == "511" |
  p2008extended$p0412_3 == "512" |p2008extended$p0412_3 == "515", NA)
summary(p2008extended$p0412_3)
with(p2008extended,table(p0412_3))

summary(p2008extended$p0412_4) #Accessibility of shops |businesses (daily shopping) by bicycle
p2008extended$p0412_4 <- replace(p2008extended$p0412_4, p2008extended$p0412_4 == "Verweigert" | 
  p2008extended$p0412_4 == "WeißNicht" |
  p2008extended$p0412_4 == "102" |p2008extended$p0412_4 == "103" |
  p2008extended$p0412_4 == "104" |p2008extended$p0412_4 == "105" |
  p2008extended$p0412_4 == "107" |p2008extended$p0412_4 == "109", NA)
summary(p2008extended$p0412_4)
with(p2008extended,table(p0412_4))

barplot(table(p2008extended$p0412_1)) #Accessibility of workplace by bicycle
p0412_1<-p2008extended$p0412_1
levels(p0412_1)
levels(p0412_1)[c(6:18)] <- "GarNicht"
summary(p0412_1)
barplot(table(p0412_1))
p0412_1<-na.exclude(p0412_1)
barplot(table(p0412_1))
table(p0412_1)

barplot(table(p2008extended$p0412_2)) #Accessibility of apprenticeship location by bicycle
p0412_2<-p2008extended$p0412_2
summary(p0412_2)
levels(p0412_2)
levels(p0412_2)[c(6:16)] <- "GarNicht"
barplot(table(p0412_2))
p0412_2<-na.exclude(p0412_2)
barplot(table(p0412_2))
table(p0412_2)

barplot(table(p2008extended$p0412_3)) #Accessibility of school by bicycle
p0412_3<-p2008extended$p0412_3
summary(p0412_3)
levels(p0412_3)
levels(p0412_3)[c(6:17)] <- "GarNicht"
barplot(table(p0412_3))

barplot(table(p2008extended$p0412_4)) #Accessibility of shops |businesses (daily shopping) by bicycle
p0412_4<-p2008extended$p0412_4
summary(p0412_4)
levels(p0412_4)
levels(p0412_4)[c(6:14)] <- "GarNicht"
barplot(table(p0412_4))

par(mfrow=c(2,2))
barplot(table(p0412_1),main="workplace") #Accessibility of workplace by bicycle
barplot(table(p0412_2),main="apprenticeship") #Accessibility of apprenticeship location by bicycle
barplot(table(p0412_3),main="school") #Accessibility of school by bicycle
barplot(table(p0412_4),main="shops") #Accessibility of shops |businesses (daily shopping) by bicycle

save(p2008extendedAS, file="ExLab5_MID2008_Descriptive\\p2008extendedAS.Rdata")

