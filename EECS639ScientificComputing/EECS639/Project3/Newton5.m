%Newton Method on the fifth fractal created by (x^2+9)(x^2+36)
function color = Newton5(z)
x1 = z; %initial answer to be updated
x2 = 0; %checks difference between previous and current
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
 
    %performing newtons method
    %x2 = x1 - (((x1^2-1)*(x1^2+.16))/(4*x1^3 - 1.68*x1));
    x2 = x1 - (((x1^2+9)*(x1^2+36))/(4*(x1)^3+90*x1));
    x1 = x2;
    x2 = x2 - x1;
    
end




color = 'k';
