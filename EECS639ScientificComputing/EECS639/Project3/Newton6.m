%Newton Method on the sixth fractal created by (x^2+2)(x^2-3)
function color = Newton6(z)
x1 = z; %initial answer to be updated
x2 = 0; %checks difference between previous and current
for i=2:21
 if(abs(x2)<0.001)
     if(abs(x1-i*sqrt(2))<.001) % root 1 was found
         color = 'm';
         return;
     end
     if(abs(x1+i*sqrt(2))<.001) %root 2 was found
         color = 'y';
         return;
     end
     if(abs(x1-i*sqrt(3))<.001)%root 3 was found
         color = 'b';
         return;
     end
     if(abs(x1+i*sqrt(3))<.001) %root 4 was found
         color = 'c';
         return;
     end
 end
 
    %performing newtons method
    %x2 = x1 - (((x1^2-1)*(x1^2+.16))/(4*x1^3 - 1.68*x1));
    %x2 = x1 - (((x1^2+9)*(x1^2+36))/(4*(x1)^3+90*x1));
    x2 = x1 - ((x1^2+2)*(x1^2-3)/(4*x1^3-2*x1));
    x1 = x2;
    x2 = x2 - x1;
    
end




color = 'k';
