function p = predict(Theta1, Theta2, X)
%PREDICT Predict the label of an input given a trained neural network
%   p = PREDICT(Theta1, Theta2, X) outputs the predicted label of X given the
%   trained weights of a neural network (Theta1, Theta2)

% Useful values
m = size(X, 1);
num_labels = size(Theta2, 1);

% You need to return the following variables correctly 
p = zeros(size(X, 1), 1);

% ====================== YOUR CODE HERE ======================
% Instructions: Complete the following code to make predictions using
%               your learned neural network. You should set p to a 
%               vector containing labels between 1 to num_labels.
%
% Hint: The max function might come in useful. In particular, the max
%       function can also return the index of the max element, for more
%       information see 'help max'. If your examples are in rows, then, you
%       can use max(A, [], 2) to obtain the max for each row.
%


X = [ones(m, 1) X];     % 5000 x 401

for e=1:m    % for each example 
    x = X(e,:)';  % 401 x 1

    A2 = sigmoid(Theta1*x); % 25 x 401 times 401 x 1 = 25 x 1

    A2 = A2';
    q = size(A2, 1);

    A2 = [ones(q, 1) A2];   

    A3 = sigmoid(Theta2*A2');    % 10 x 26 times 26 x 1 = 10 x 1

    [h,I] = max(A3');
    p(e) = I;

end
% =========================================================================


end
