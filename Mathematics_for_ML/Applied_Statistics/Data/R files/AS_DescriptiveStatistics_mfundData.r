#-------------------------------------------------------------------------------------
#The data is contained in file mfund.data with space delimited values.
#The first row gives the variable names.
setwd("c:\\Users\\Regine\\Documents\\Lacie\\Daten\\R\\EigeneR_Uebungen\\")
mfund.data <- read.table(file = "mfund.data", header = T)
library(MASS)
attach(mfund.data)
options(width = 70, digits = 2)
mfund.data[1:10, ]
#   load exprat type assets return5 return1                     name
#1     2   1.06    2  15252     117      45        Fidelity_Magellan
#2     3   0.37    4   7709      63      37            Windsor_Funds
#3     1   0.55    4   7643      92      30 Investment_Co_of_America
#4     1   0.77    4   6792      81      33    Washington_Mutual_Inv
#5     2   0.65    5   4790      62      28         Fidelity_Puritan
#6     2   0.70    5   4089      56      31      Fidelity_Equity-Inc
#7     1   0.75    4   3999      61      25               Pioneer_II
#8     1   0.60    4   3899      72      24          American_Mutual
#9     3   1.00    2   3761      89      27    Twentieth_Cent:Select
#10    1   0.50    4   3379      67      27          Affiliated_Fund


str(mfund.data)
#'data.frame':   40 obs. of  7 variables:
# $ load   : num  2 3 1 1 2 2 1 1 3 1 ...
# $ exprat : num  1.06 0.37 0.55 0.77 0.65 0.7 0.75 0.6 1 0.5 ...
# $ type   : num  2 4 4 4 5 5 4 4 2 4 ...
# $ assets : num  15252 7709 7643 6792 4790 ...
# $ return5: num  117.4 62.8 92 81.5 62.4 ...
# $ return1: num  44.9 37.1 30.2 32.8 27.7 ...
# $ name   : Factor w/ 40 levels "Affiliated_Fund",..: 14 39 22 38 15 11 30 5 35 1 ...
table(load)
#load
# 1  2  3
#21  5 14
table(type)
#type
# 1  2  4  5
# 4 12 18  6
n<-length(load) #[1] 40
table(load)/n
#load
#    1     2     3
#0.525 0.125 0.350
table(type)/n
#type
#   1    2    4    5
#0.10 0.30 0.45 0.15
sum(table(type)/n) #[1] 1

#Grouping
#Quantitative variables can be grouped by using cut, where the bin limits have to be provided
exprat.group <- cut(exprat, breaks = c(0, 0.5, 1, 1.5, 2))
table(exprat.group)/n
#exprat.group
#(0,0.5] (0.5,1] (1,1.5] (1.5,2]
#  0.125   0.750   0.100   0.025

par(mfrow = c(1, 2))
barplot(table(load), main = "load")
barplot(table(type), main = "type")

par(mfrow = c(1, 2))
pie(table(load), main = "load")
pie(table(type), main = "type")

par(mfrow = c(1, 1))
freq.load <- table(load)
names(freq.load) <- c("large charge", "low charge", "no charge")
pie(freq.load, labels = names(freq.load), main = "load")

hist(exprat)

par(mfrow = c(2, 2))
hist(exprat, breaks = 15, main = "breaks=15")
hist(exprat, breaks = 8, main = "breaks=8")
hist(exprat, breaks = 5, main = "breaks=5")
hist(exprat, breaks = 3, main = "breaks=3")

table(load)/n
#load
#    1     2     3
#0.525 0.125 0.350
cumsum(table(load)/n)
#    1     2     3
#0.525 0.650 1.000

par(mfrow = c(1, 1))
plot(ecdf(load))

mean(load)
#[1] 1.8
median(load)
#[1] 1
mean(exprat)
#[1] 0.76
median(exprat)
#[1] 0.77
range(load)


table(load)
#load
#1 2 3
#21 5 14
table(exprat.group)
#exprat.group
#(0,0.5] (0.5,1] (1,1.5] (1.5,2]
#5 30 4 1
table(cut(exprat, breaks = seq(0, 2, length = 11)))
#(0,0.2] (0.2,0.4] (0.4,0.6] (0.6,0.8] (0.8,1] (1,1.2] (1.2,1.4]
#0 3 7 16 9 3 1
#(1.4,1.6] (1.6,1.8] (1.8,2]
#1 0 0

quantile(exprat, probs = seq(0, 1, 0.2))
#0% 20% 40% 60% 80% 100%
#0.21 0.57 0.70 0.79 0.91 1.51
quantile(load, probs = seq(0, 1, 0.2))
#0% 20% 40% 60% 80% 100%
#1 1 1 2 3 3

par(mfrow = c(2, 2))
boxplot(exprat, main = "expense ratio")
boxplot(return1, main = "return after 1 year")
boxplot(return5, main = "return after 5 years")

par(mfrow = c(2, 1))
boxplot(return1 ~ type, main = "Returns after 1 year by type")
boxplot(return1 ~ load, main = "Returns after 1 year by load")

which(is.na(return5))
#[1] 37
(1:n)[is.na(return5)]
#[1] 37
apply(cbind(return1, return5, exprat)[-37, ], 2, sd)
#return1 return5 exprat
#8.33 22.48 0.25
apply(cbind(return1, return5, exprat)[-37, ], 2, IQR)
#return1 return5 exprat
#10.52 28.26 0.26
apply(cbind(return1, return5, exprat)[-37, ], 2, mad) #Median Absolute Deviation
#return1 return5 exprat
#7.10 22.16 0.18

sd(return5) #[1] NA
sd(return5,na.rm=T) #[1] 22.48333

library(fBasics)
skewness(return1) #[1] 0.6
kurtosis(return1) #[1] -0.52

summary(mfund.data)

table(load, type)
ftable(load, type)

table(load, type, exprat.group)
ftable(load, type, exprat.group) #Create ‘flat’ contingency tables.

par(mfrow = c(2, 1))
plot(assets, return1, xlab = "assets", ylab = "return after 1 year")
plot(assets, return5, xlab = "assets", ylab = "return after 5 years")

pairs(cbind(exprat, assets, return1, return5))

cor(return1, return5, use = "complete.obs")

par(mfrow = c(1, 1))
plot(return1 ~ assets, data = mfund.data, pch = type, col = type)
legend(10000, 30, legend = paste("type", c(1, 2, 4, 5)),
col = c(1, 2, 4, 5), pch = c(1, 2, 4, 5))

par(mfrow = c(1, 1))
plot(return1 ~ assets, data = mfund.data, pch = load, col = load)
legend(10000, 30, legend = paste("load", 1:3), col = 1:3, pch = 1:3)

#data preparation/management
str(mfund.data)
type_factor <- as.factor(type)
levels(type_factor) <-c("ca","go","gio","eio")
with(mfund.data,table(type))
mfund.data<-cbind(mfund.data,type_factor)
head(mfund.data)
str(mfund.data)

levels(type_factor)
levels(type_factor)[c(1,2)]<-"1and2"
levels(type_factor)
levels(type_factor)[c(2,3)]<-"4and5"
levels(type_factor)

levels(type_factor)
levels(type_factor)[c(1,4)]<-"1and4"
levels(type_factor)
levels(type_factor)[c(2,3)]<-"2and3"
levels(type_factor)

colnames(mfund.data)
colnames(mfund.data)[1]<-"unload"
colnames(mfund.data)
rownames(mfund.data)
rownames(mfund.data)[1]<-"Trial.1"
rownames(mfund.data)

#sorting your data
mfund.data[order(type),c(1:5)]
mfund.data[rev(order(type)),c(1:5)]
mfund.data[order(type,load),]
#rule: if in doubt, sort using more variables than you think you need
#put only some variables in the sorted dataframe:
#specify the column numbers in the sequence we want them to appear
mfund.data[order(type,load),c(3,1,2,4,5)]
#or more cumbersome:
mfund.data[order(type,load),c("type","load","exprat","assets")]
#using logical conditions to select rows
mfund.data[type==1,]
mfund.data[assets>median(assets)&type<4,]  #median(assets): 2372
mfund.data[,sapply(mfund.data,is.numeric)]
mfund.data[,sapply(mfund.data,is.factor)]
mfund.data[,sapply(mfund.data,is.character)]
#drop rows with negative subcripts
mfund.data[-(6:15),]
