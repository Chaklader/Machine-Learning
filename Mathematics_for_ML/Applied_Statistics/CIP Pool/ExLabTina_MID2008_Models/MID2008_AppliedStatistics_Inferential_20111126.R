
setwd("c:\\Users\\gerike\\Documents\\Lacie\\Lehre\\AppliedStatisticsInTransport\\WS11_12\\")

#Data sets in the directory ExLabTina_MID2008_Models\\:
#p2008extendedASOriginal.Rdata: the same as p2008 but with more variables and some coded variables, prepared by Regine Gerike for the course Applied Statistics 
#p2008extendedAS.Rdata: the same as p2008extendedASOriginal but for your work

load("ExLabTina_MID2008_Models\\p2008extendedASOriginal.Rdata")
load("ExLabTina_MID2008_Models\\p2008extendedAS.Rdata")

#--------------------------------------------------------------
#--------------------------------------------------------------
 
#create the copy of the data set for your work:
load("ExLabTina_MID2008_Models\\p2008extendedASOriginal.Rdata")
p2008extendedAS<-p2008extendedASOriginal
save(p2008extendedAS, file="ExLabTina_MID2008_Models\\p2008extendedAS.Rdata")
#load("ExLabTina_MID2008_Models\\p2008extendedAS.Rdata")
rm(p2008extendedASOriginal)
ls()


#--------------------------------------------------------------------------
#Example: Chi-Squared Contingency Tables,Crawely 301, example from lecture probabilities
(o<-c(22,25,30,8,5,10))  #observed frequencies
(e<-c(23.1,23.1,30.8,6.9,6.9,9.2)) #expected frequencies for independent events
(o_minus_e_squared<-(o-e)^2)
(o_minus_e_squared_divided_by_e<-((o-e)^2)/e)
sum(o_minus_e_squared_divided_by_e)   #Test statistic chi-squared: 0.9975532
# d.f.=(r-1)*(c-1)=(3-1)*(2-1)=2
#qchisq(p, df), p=vector of probabilities
qchisq(0.95,2)  #5.991465, cuts 5% of the right hand tail  
#dchisq(x, df)
1-pchisq(0.9975532,2) #0.6072731
#With R-command chisq.test:
(count<-matrix(c(22,25,30,8,5,10),nrow=3))
chisq.test(count)
#        Pearson's Chi-squared test
#data:  count 
#X-squared = 0.9976, df = 2, p-value = 0.6073
#End Example
#--------------------------------------------------------------------------


#-----------------------------------------------------------------------------------
#Real world data: MID2008:
#The descriptive analysis could also be done for relevant subgroups 
#e.g. accessibility by car depending on gender
#calculate: 2x5 contingency table (later on we can test for equal frequency 
#distribution between men and women (50:50 chance), Chi2 test)

summary(p2008extendedAS$hp_sex)
#    m     w     k.A. 
# 29948 30761     4
p2008extendedAS$hp_sex <- replace(p2008extendedAS$hp_sex, p2008extendedAS$hp_sex == "k.A.", NA)
summary(p2008extendedAS$hp_sex) #4 NA
hp_sex<-p2008extendedAS$hp_sex
summary(hp_sex)
levels(hp_sex)
levels(hp_sex)[3] <- "w"
barplot(table(hp_sex))

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

p0414_1<-p2008extendedAS$p0414_1
summary(p0414_1)
levels(p0414_1)
levels(p0414_1)[7:19] <- "GarNicht"
barplot(table(p0414_1))

(hp_sex_p0414_1<-table(hp_sex,p0414_1))
#      p0414_1
#hp_sex SehrGut  Gut Eingerm Schlecht SehrSchlecht GarNicht
#     m    5300 2878     394      134           50      485
#     w    6220 2556     311      175           61      506
chisq_test<-rbind(hp_sex_p0414_1,apply(hp_sex_p0414_1,2,sum))
chisq_test<-cbind(chisq_test,apply(chisq_test,1,sum))
chisq_test
rownames(chisq_test)
rownames(chisq_test) <-c("m","w","Total")
colnames(chisq_test)
colnames(chisq_test) <- c("SehrGut","Gut","Eingerm","Schlecht","SehrSchlecht","GarNicht","Total")

chisq_indep<-chisq_test

for (i in 1:6) {
  chisq_indep[1,i]<-chisq_indep[3,i]*chisq_indep[1,7]/chisq_indep[3,7]
  chisq_indep[2,i]<-chisq_indep[3,i]*chisq_indep[2,7]/chisq_indep[3,7]
}

chisq_indep

(chisq_test_diff<-matrix(0, nrow = 2, ncol = 6))


for (i in 1:6) {
  chisq_test_diff[1,i]<-chisq_indep[1,i]-chisq_test[1,i]
  chisq_test_diff[2,i]<-chisq_indep[2,i]-chisq_test[2,i]
}

chisq_test_diff

#test statistics: sum(((O-E)^2)/E))

(chisq_test_statistics<-matrix(0, nrow = 2, ncol = 6))


for (i in 1:6) {
  chisq_test_statistics[1,i]<-(chisq_test_diff[1,i]^2)/chisq_indep[1,i]
  chisq_test_statistics[2,i]<-(chisq_test_diff[2,i]^2)/chisq_indep[2,i]
}

sum(chisq_test_statistics1) ##Test statistic chi-squared: 91.25618

# d.f.=(r-1)*(c-1)=(2-1)*(6-1)=5
#qchisq(p, df), p=vector of probabilities
qchisq(0.95,5)  #11.07050, cuts 5% of the right hand tail  
#dchisq(x, df)
1-pchisq(91.25618,5) #0
#With R-command chisq.test:
chisq.test(chisq_test[1:2,1:6])
#  Pearson's Chi-squared test
#data:  chisq_test[1:2, 1:6] 
#X-squared = 91.2562, df = 5, p-value < 2.2e-16
#We cannot accept the hypothesis that both variables are independent.
#Chi square indicates significant difference.

#chisq_test, O-values:
#      SehrGut  Gut Eingerm Schlecht SehrSchlecht GarNicht Total
#m        5300 2878     394      134           50      485  9241
#w        6220 2556     311      175           61      506  9829
#Total   11520 5434     705      309          111      991 19070

#chisq_indep, E-values:
#        SehrGut      Gut  Eingerm Schlecht SehrSchlecht GarNicht Total
#m      5582.397 2633.225 341.6311 149.7362     53.78873 480.2219  9241
#w      5937.603 2800.775 363.3689 159.2638     57.21127 510.7781  9829
#Total 11520.000 5434.000 705.0000 309.0000    111.00000 991.0000 19070

#chisq_test_diff, differences:
#          [,1]      [,2]     [,3]      [,4]      [,5]      [,6]
#[1,]  282.3975 -244.7754 -52.3689  15.73618  3.788726 -4.778133
#[2,] -282.3975  244.7754  52.3689 -15.73618 -3.788726  4.778133

#Barplot for visual check:
for_Barplot<-cbind(hp_sex,p0414_1)
#check for missing values:
(isna<-apply(apply(for_Barplot,2,is.na),2,sum))    #Number of NAs for all variables
# hp_sex p0414_1 
#      4   41643
table(complete.cases(for_Barplot)) #TRUE 19070
for_Barplot[is.na(for_Barplot[,1]),] #p0414_1 == NA for all hp_sex == NA
par(mfrow=c(3,1))
#table(for_Barplot[for_Barplot[,1]==1,2],useNA="ifany")
barplot(table(for_Barplot[for_Barplot[,1]==1,2],useNA="ifany"))
barplot(table(for_Barplot[for_Barplot[,1]==1,2],useNA="no"))
barplot(table(for_Barplot[for_Barplot[,1]==1,2],useNA="always"))
#Barplots for men/women
par(mfrow=c(2,1))
barplot(table(for_Barplot[for_Barplot[,1]==1,2]),main="m, p0414_1") #useNA="no": Default
barplot(table(for_Barplot[for_Barplot[,1]==2,2]),main="w, p0414_1") #useNA="no": Default

#more women than man indicate 1 = very good accessibility of workplace by car (54 vs 46%)
#more men than women indicate 2 = good and 3= reasonable accessibilty (53 vs 47%, 56 vs 44% )  
#Bar charts illustrate that the distribution in each group men/women seems to be similar
#chi square indicates significant difference


save(p2008extendedAS, file="ExLab5_MID2008_Descriptive\\p2008extendedAS.Rdata")
