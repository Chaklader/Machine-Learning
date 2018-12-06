##-------------------------------------------------------------------------------------
#commands for the presentation AppliedStatR_Distributions_20100824.pptx:

#Probability functions:
#number of permutations: factorial(x)
x<-0:6
par(mfrow=c(1,1))
plot(x,factorial(x),type="s",main="factorial(x)",
log="y",cex.lab = 1.5,cex.axis=1.5,cex.main=1.5)

#Binomial coefficient: choose(n,x)

#Important Distributions in R
#beta
#binom
#chauchy
#exp
#chissq
#f
#gamma
#geom
#hyper
#lnorm
#logis
##nbinom
#norm
#pois
#signrank
#t
#unif
#weibull
#wilcox

#cdf and pdf for discrete random variables, example: rolling a die
x<-(1:6)
y<-table(x)
par(mfrow = c(1, 2))
plot(x, y, type = "h", col = "red", lwd = 2, xlab = "Number observed", ylab = "f(X)",
main = "pdf")
plot(ecdf(x),col="red",xlab = "Number observed", ylab = "F(X)",main="cdf")

#or as a step function:
par(mfrow = c(1, 1))
(y1<-cumsum(table(x)))
plot(x,y1,type="s",col="red",xlab = "Number observed", ylab = "F(X)",
main="cdf",cex.axis=1.5,lwd=4,cex.lab=1.5,cex.main=1.5)

#rolling two dice
x<-(2:12)
y<-c(1/36,1/18,1/12,1/9,5/36,
1/6,5/36,1/9,1/12,1/18,1/36)
par(mfrow = c(1, 2))
plot(x, y, type = "h", col = "red",
lwd = 2, xlab = "Number observed",
ylab = "f(X)",main = "pdf")
plot(ecdf(x),col="red",xlab = 
"Number observed", ylab = "F(X)",main="cdf")

#binomial distribution
dbinom(x = 5, size = 7, prob = 0.5)
dbinom(x = c(3, 4, 5), size = 7, prob = 0.5)
x1 <- pbinom(q = 5, size = 7, prob = 0.5,
lower.tail = TRUE)
x2 <- pbinom(q = 5, size = 7, prob = 0.5,
lower.tail = FALSE)
x1 + x2

qbinom(p = 0.4, size = 7, prob = 0.5)

x <- rbinom(8, size = 7, prob = 0.5)
x
set.seed(1)
x <- rbinom(8, size = 7, prob = 0.5)
x
set.seed(53)
y <- rbinom(8, size = 7, prob = 0.5)
#[1] 4 2 2 4 4 4 2 3
set.seed(1)
z <- rbinom(8, size = 7, prob = 0.5)
z

x <- c(0:20)
y <- dbinom(x, size = 20, prob = 0.67)
z <- pbinom(x, size = 20, prob = 0.67)
par(mfrow = c(1, 2))
plot(x, y, type = "h", col = "red", lwd = 2, xlab = "x value", ylab = "probability",
main = "pmf")
plot(x, z, pch = 16, col = "red", xlab = "x value", ylab = "probability", main = "cdf")
segments(x, z, x + 1, z, col = "red", lwd = 2)

#Poisson distribution
x<-0:20
y1<-dpois(x,lambda=1)
y2<-dpois(x,lambda=5)
y3<-dpois(x,lambda=10)
z1<-ppois(x,lambda=1)
z2<-ppois(x,lambda=5)
z3<-ppois(x,lambda=10)
cols<-c("red","blue","black")
labs<-c(expression(lambda==1,lambda==5,lambda==10))
#expression: Creates or tests for objects of mode "expression". 

par(mfrow=c(1,2))
barplot(rbind(y1,y2,y3),0.2,col=cols,border=cols,xlim=c(0,40),
space=c(0,5),axis.lty=1,names.arg=c(0:20),beside=T,xlab="x value",
ylab="probability",main="pdf")
box() #draws a box around the current plot in the given color and linetype
legend("topright",inset=0.01,labs,lwd=2,col=cols,box.col="white")
plot(rbind(x,x,x),rbind(z1,z2,z3),pch=16,col=cols,xlab="x value",
ylab="probability",main="cdf")
segments(x,z1,x+1,z1,col=cols[1],lwd=2) 
#segments: Draw line segments between pairs of points. 
segments(x,z2,x+1,z2,col=cols[2],lwd=2)
segments(x,z3,x+1,z3,col=cols[3],lwd=2)
legend("bottomright",inset=0.01,labs,lwd=2,col=cols,box.col="white")

#Example Auto Parts
dpois(1,1)
ppois(1,1)

par(mfrow = c(1, 2))
cols <- c("blue", "red", "black", "darkgreen")
labs <- c(expression(paste(mu == 0, ", ", sigma == 1)), expression(paste(mu ==
0, ", ", sigma == 4)), expression(paste(mu == 0, ", ", sigma == 0.8)), expression(paste(mu ==
2, ", ", sigma == 1)))
x <- seq(-7, 7, 0.05)
plot(x, dnorm(x, mean = 0, sd = 1), type = "l", col = cols[1], lwd = 2, ylim = c(0,
0.8), xlab = "x value", ylab = "probability", main = "pdf")
lines(x, dnorm(x, mean = 0, sd = 2), col = cols[2], lwd = 2)
lines(x, dnorm(x, mean = 0, sd = 0.6), col = cols[3], lwd = 2)
lines(x, dnorm(x, mean = 4, sd = 1), col = cols[4], lwd = 2)
legend("topright", inset = 0.01, labs, lwd = 2, col = cols, box.col = "white")
plot(x, pnorm(x, mean = 0, sd = 1), type = "l", col = cols[1], lwd = 2, xlab = "x value",
ylab = "probability", main = "cdf")
lines(x, pnorm(x, mean = 0, sd = 2), col = cols[2], lwd = 2)
lines(x, pnorm(x, mean = 0, sd = 0.6), col = cols[3], lwd = 2)
lines(x, pnorm(x, mean = 4, sd = 1), col = cols[4], lwd = 2)
legend("topleft", inset = 0.01, labs, lwd = 2, col = cols, box.col = "white")


#------------------------------------------------------------------------
#commands for the figures in the slides on distributions:

#Binomial distribution: shape
x <- c(0:10)
y <- dbinom(x, size = 10, prob = 0.3)
par(mfrow = c(2, 2))
plot(x, y, type = "h", col = "red", lwd = 5, xlab = "x value", ylab = "probability",main="pdf, p=0.3",cex.axis=1.0)
y <- dbinom(x, size = 10, prob = 0.5)
plot(x, y, type = "h", col = "red", lwd = 5, xlab = "x value", ylab = "probability",main="pdf, p=0.5",cex.axis=1.0)
y <- dbinom(x, size = 10, prob = 0.7)
plot(x, y, type = "h", col = "red", lwd = 5, xlab = "x value", ylab = "probability",main="pdf, p=0.7",cex.axis=1.0)
y <- dbinom(x, size = 10, prob = 0.9)
plot(x, y, type = "h", col = "red", lwd = 5, xlab = "x value", ylab = "probability",main="pdf, p=0.9",cex.axis=1.0)

#Poisson distribution
par(mfrow = c(2, 2))
x <- c(0:20)
y1 <- dpois(x, lambda = 1)
plot(x,y1,pch=16,main="Lambda=1")
y2 <- dpois(x, lambda = 5)
plot(x,y2,pch=16,main="Lambda=5")
y3 <- dpois(x, lambda = 10)
plot(x,y3,pch=16,main="Lambda=10")
y4 <- dpois(x, lambda = 15)
plot(x,y4,pch=16,main="Lambda=15")
z1 <- ppois(x, lambda = 1)
plot(x,z1,pch=16,main="Lambda=1")
z2 <- ppois(x, lambda = 5)
plot(x,z2,pch=16,main="Lambda=5")
z3 <- ppois(x, lambda = 10)
plot(x,z3,pch=16,main="Lambda=10")
z4 <- ppois(x, lambda = 15)
plot(x,z4,pch=16,main="Lambda=15")
