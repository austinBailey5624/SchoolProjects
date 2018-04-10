function result = Newton1A()

Guess = [1 1 0];
GuessTemp = [1 1 0];

PracticalHessian = [4 0 -4*GuessTemp(1);0 6 -6*GuessTemp(2);0 0 0];


iterator = 1;
while(iterator<41 && (abs(GuessTemp(1))>.001 || abs(GuessTemp(2))>.001))
    Temp = Gaussian(PracticalHessian);
    GuessTemp(1) = Temp(1, 3);
    GuessTemp(2) = Temp(2,3);
    PracticalHessian = [4 0 -4*GuessTemp(1);0 6 -6*GuessTemp(2);0 0 0];
    Guess = Guess - GuessTemp;
    iterator = iterator+1;
end
result = [Guess(1) Guess(2)];