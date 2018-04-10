%preforming the Secant operation on the sixth equation
%(x^2+2)(x^2-3)
function color = Secant6(z1,z2)
x0=z1;
x1=z2;
x2=0;
for i=2:21
 if(abs(x2)<0.0001)
     if(x1 == 3i) % root 1 was found
         color = 'g';
         return;
     end
     if(x1 == -3i) %root 2 was found
         color = 'y';
         return;
     end
     if(x1 == 6i) %root 3 was found
         color = 'b';
         return;
     end
     if(x1 == -6i) %root 4 was found
         color = 'c';
         return;
     end
 end
 
    %performing secant method

%    x2=x1-(x1^2-1)*(x1^2+.16)*((x1-x0)/((x1^2-1)*(x1^2+.16)-(x0^2-1)*(x0^2+.16)));
%    x2= (x0*(x1^2-1)*(x1^2+.16) -x1*(x0^2-1)*(x0^2+.16) )/((x1^2-1)*(x1^2+.16) -(x0^2-1)*(x0^2+.16) );
    x2 = (x0 * (x1^2+9)*(x1^2+36)- x1 * (x0^2+9)*(x0^2+36))/((x1^2+9)*(x1^2+36)-(x0^2+9)*(x0^2+36));
    x0=x1;
    x1=x2;
    x2 = x2-x1;
    
    
end




color = 'k';