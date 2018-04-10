function color = Secant(z1,z2)
x0=z1;
x1=z2;
x2=0;
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
 
    %performing secant method

%    x2=x1-(x1^2-1)*(x1^2+.16)*((x1-x0)/((x1^2-1)*(x1^2+.16)-(x0^2-1)*(x0^2+.16)));
    x2= (x0*(x1^2-1)*(x1^2+.16) -x1*(x0^2-1)*(x0^2+.16) )/((x1^2-1)*(x1^2+.16) -(x0^2-1)*(x0^2+.16) );
    x0=x1;
    x1=x2;
    x2 = x2-x1;
    
    
end




color = 'k';