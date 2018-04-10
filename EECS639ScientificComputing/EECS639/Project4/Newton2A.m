function result = Newton2A()

Guess = [-1.2 1 0];
GuessTemp = [-2 2 0];

PracticalHessian = [ (2+12*GuessTemp(1)*GuessTemp(1)) -4*GuessTemp(1) -2+2*GuessTemp(1)-2*GuessTemp(2)+4*GuessTemp(1)*GuessTemp(1)*GuessTemp(1); -2 2 2*GuessTemp(2)-2*GuessTemp(1)*GuessTemp(1); 0 0 1];

iterator=1;
while(iterator<41 && (abs(GuessTemp(1))>.001 || abs(GuessTemp(1))>.001))
    Temp = Gaussian(PracticalHessian);
%    disp(Temp);
    GuessTemp(1) = Temp(1,3);
    GuessTemp(2) = Temp(2,3);
    PracticalHessian = [ (2+12*GuessTemp(1)*GuessTemp(1)) -4*GuessTemp(1) -2+2*GuessTemp(1)-2*GuessTemp(2)+4*GuessTemp(1)*GuessTemp(1)*GuessTemp(1); -2 2 2*GuessTemp(2)-2*GuessTemp(1)*GuessTemp(1); 0 0 1];
    Guess = Guess - GuessTemp;
    iterator = iterator+1;
end
result = [Guess(1) Guess(2)];