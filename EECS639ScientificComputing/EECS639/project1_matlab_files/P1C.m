% Script P1C
% Illustrates ShowEllipse

close all

% Display the ellipse (x/3)^2 + (y/2)^2 = 1
% and what is obtained by rotating it counterclockwise pi/6, pi/3, and pi/2 
% radians.

for i=1:4
   subplot(2,2,i)
   ShowEllipse(MakeEllipse(RotateConic(MakeConic(1/9,0,1/4,0,0,-1),(i-1)*pi/6)))
   title(sprintf('angle = %3d degrees',(i-1)*30))
end

% Display 2x^2 + xy + 3y^2 - x + y - 2 = 0

figure
Eta = MakeEllipse(MakeConic(2,1,3,-1,1,-2));
ShowEllipse(Eta)

title(sprintf('a = %6.4f  b = %6.4f   (h,k) = (%6.4f,%6.4f)  phi = %6.4f',...
    Eta.a, Eta.b, Eta.h, Eta.k, Eta.phi))


