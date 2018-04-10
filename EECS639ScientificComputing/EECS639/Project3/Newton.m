function color = Newton(z)
x1 = z; %initial answer to be updated
x2 = 0; %checks difference between previous and current
for i=2:21
 if(abs(x2)<0.0001)
     if(x1 == -1) % root 1 was found
         color = 'y';
         return;
     end
     if(x1 == 1) %root 2 was found
         color = 'r';
         return;
     end
     if(x1 == -0.4i) %root 3 was found
         color = 'b';
         return;
     end
     if(x1 == 0.4i) %root 4 was found
         color = 'g';
         return;
     end
 end
 
    %performing newtons method
    x2 = x1 - (((x1^2-1)*(x1^2+.16))/(4*x1^3 - 1.68*x1));
    x1 = x2;
    x2 = x2 - x1;
    
end




color = 'k';

% f = (z^2-1)(z^2+.16)
% fprime = 4z^3 - 1.68z
% Input:
% z = complex number
%
% Output:
% color = the color associated with the root found by Newton’s Method
% according to the following key:
% color = ’y’, if Newton’s Method found z_1
% ’r’, if Newton’s Method found z_2
% ’b’, if Newton’s Method found z_3
% ’g’, if Newton’s Method found z_4
% ’k’, if Newton’s Method was unsuccessful
% after 20 iterations.
% More precisely, "unsuccessful" means that Matlab cannot reduce
% (z^2-1)(z^2+0.16) to less than 0.0001 (in absolute value) in at most
% 20 Newton iterations.