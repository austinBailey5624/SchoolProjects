% Script P1A
%
% Plots the coefficients A, B, C, D, E, and F as the conic
%
%        2x^2 + xy + 3y^2 - x + y - 2
%
% is rotated around the origin (0,0).

close all;
n = 200;
Kappa = MakeConic(2,1,3,-1,1,-2);
phi = linspace(0,2*pi,n)';
P = zeros(n,6);

% Store the A, B, C, D, E, and F values in the columns of P.
for k=1:n
   Z = RotateConic(Kappa,phi(k));
   P(k,:) = [Z.A Z.B Z.C Z.D Z.E Z.F];
end

% Plot the A, B, and C values
plot(phi,P(:,1),'-',phi,P(:,2),':',phi,P(:,3),'--')
xlabel('phi (the counter-clockwise rotation angle)')
legend('A','B','C');
title('Values of A, B, and C when 2x^2 + xy + 3y^2 - x + y - 2 is rotated \phi radians')

% Plot the D, E, and F values
figure;
plot(phi,P(:,4),'-',phi,P(:,5),':',phi,P(:,6),'--')
xlabel('phi (the counter-clockwise rotation angle)')
legend('D','E','F');
title('Values of D, E, F when 2x^2 + xy + 3y^2 - x + y - 2 is rotated \phi radians')
