clear all

T = 1;
N = 10000;
dt = T/N;

z(1) = 0;
t = dt*[0:1:N-1];  % time grid

% simulate the trajectory of sigma_t
vol = sqrt(dt) * (.1+abs(cumsum(randn(size(t)))));

% simulate the process z
for n=1:N-1
    z(n+1) = z(n) + vol(n)*sqrt(dt)*randn(1,1);
end

% plot realized changes in z
figure(1)
hold off
axis('square');
plot(t(2:end),diff(z),'-o');

hold on

% Input the window size for variance estimation
window = input('\n Input the window for estimating volatility \n');


figure(2)
axis('square');
hold off

window = 200;
% I use the filter function instead of manually summing up
% squares of delta_z.
varhat = filter(ones(1,window)./window,[1], diff(z).^2)./dt;

plot(t(2:end),varhat.^.5,'r','LineW',2)
hold on
plot(t,vol,'g--','LineW',2);
