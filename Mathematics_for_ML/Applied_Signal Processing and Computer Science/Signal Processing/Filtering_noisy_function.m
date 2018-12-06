close all
clear all
clc

fs=10000;   % sampling rate : 10 KHz
T=1/fs;     % Period per sample [sec]--> 1 sec divided by sampling rate 
Dur=0.1;    % time T = 100ms;
t= 0:T:Dur; % Time steps
ff=-fs/2:1/Dur:fs/2; 

sig=sin(50*2*pi.*t)+0.3*sin(400*2*pi.*t);  % original 

%Add random noise

sig2=sig+ randn(1,length(t))*0.3;
SIG=fft(sig); SIG_sort=abs(fftshift(SIG));
SIG2=fft(sig2);SIG2_sort=abs(fftshift(SIG2));

%%
FIL_sort=signal(ff,1000);
FIL=iffshift(FIL_sort);

%%
fil=ifft(FIL);
fil=fftshift(fil);


SIG3=SIG2.FIL; SIG3_sort=abs(fftshift(SIG3));


sig3=ifft(SIG3);

figure;
subplot(2,1,1);plot(t,fil); title('Filter-time domain'); grid;
xlable('Timeline[sec]'); ylable('Amplitude');
subplot(2,1,2); plot(f,FIL_sort);title ('Filter- frequency domain'); grid;
xlable('frequency[Hz]');
set(gcf,'Name''Function'': Filter''Numbertitle''off');

% Time domain

figure;

subplot(3,1,1); plot(t,sig); title('Function-time domain'); grid;
xlable('Timeline[sec]'); ylable('Amplitude');
subplot(3,1,2); plot(t,sig2); title('Function noisy- time domain'); grid;
xlable('Timeline[sec]'); ylable('Amplitude');
subplot(3,1,3); plot(t,sig3); title('Function filtered- time domain'); grid;
xlable('Timeline[sec]'); ylable('Amplitude');
set(gcf,'Name','''Function'': Time domain', 'Numbertitle','off');


%Frequencies

figure;

subplot(3,1,1); plot(t,SIG_sort); title('Function-time domain'); grid;
xlable('Frequency[Hz]'); 
subplot(3,1,2); plot(f,SIG2_sort); title('Function noisy-frequency domain'); grid;
xlable('Frequency[Hz]');
subplot(3,1,3); plot(f,SIG3_sort); title('Function filtered- frequency domain'); grid;
xlable('Frequency[Hz]');
set(gcf,'Name','''Function'': Frequency domain','Numbertitle','off');




















