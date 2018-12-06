function g = sigmoidGradient(z)
%SIGMOIDGRADIENT returns the gradient of the sigmoid function
%evaluated at z
%   g = SIGMOIDGRADIENT(z) computes the gradient of the sigmoid function
%   evaluated at z. This should work regardless if z is a matrix or a
%   vector. In particular, if z is a vector or matrix, you should return
%   the gradient for each element.

g = zeros(size(z));

% ====================== YOUR CODE HERE ======================
% Instructions: Compute the gradient of the sigmoid function evaluated at
%               each value of z (z can be a matrix, vector or scalar).

sig = zeros(size(z));
for i=1:size(z)
    for j=1:size(z,2)
        sig(i,j) = 1/(1+exp(-z(i,j)));
    end
end


for i=1:size(z)
    for j=1:size(z,2)
        g(i,j) = sig(i,j)*(1 - sig(i,j));
    end
end



% =============================================================




end
