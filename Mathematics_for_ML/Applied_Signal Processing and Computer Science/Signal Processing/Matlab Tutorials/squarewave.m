close all
clear all
clc

%plot square wave
f1 = 0.025; % fundamental frequency
f2 = 3*f1;  
f3 = 5*f1;

n = 0:70; % sequence index, can be from minus infinite to plus infinite

u11 = sin(2*pi*f1.*n); % Fundamental component
u12 = sin(2*pi*f2.*n); % 3rd Harmonics
u13 = sin(2*pi*f3.*n); % 5th Harmonics

u2 = u11+1/3*u12+1/5*u13; % generated square wave

fig=figure;
subplot(4,1,1) % plot u11
set(gca,'FontSize',14)
plot(n,u11,'--.','MarkerSize',15)
title('u_1_,_1','FontSize',20)
xlim([-10 80])



subplot(4,1,2)% plot u12
set(gca,'FontSize',14)
plot(n,u12,'--.','MarkerSize',15)
title('u_1_,_2','FontSize',20)
xlim([-10 80])


subplot(4,1,3) % plot u13
set(gca,'FontSize',14)
plot(n,u13,'--.','MarkerSize',15)
title('u_1_,_3','FontSize',20)
xlim([-10 80])


subplot(4,1,4) % plot u2
set(gca,'FontSize',14)
plot(n,u2,'r--.','MarkerSize',15)
title('u_2','FontSize',20)
xlim([-10 80])

print(fig, '-dtiff','-r150','squre_wave.tif') % saving the plot

