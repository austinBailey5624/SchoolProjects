function result = SteepestDescent1()

LMax = 1;
phiLMax = 1;

LMaxHalf = 0.5;
phiLMaxHalf = 0.5;

start = 0;
starty = 0;

iterator = 1;
while( iterator < 30 )
   alpha1 = 2*(LMax^2) + 3*(phiLMax^2);
   alpha2 = 2*(LMaxHalf^2) + 3*(phiLMaxHalf^2);
   alpha3 = 2*(start^2) + 3*(starty^2);
   
   if( alpha2 < alpha1 && alpha2 < alpha3) %midpoint is lowest value
       if( alpha1 < alpha3) %LMax is less than start, move start and LMaxHalf
           start = LMaxHalf;
           starty = phiLMaxHalf;
           LMaxHalf = (LMax - start)/2 + start;
           phiLMaxHalf = (phiLMax - starty)/2 + starty;
       else %start is less than LMax half, move LMax and LMax Half
           LMax = LMaxHalf;
           phiLMax = phiLMaxHalf;
           LMaxHalf = LMaxHalf/2;
           phiLMaxHalf = phiLMaxHalf/2;
       end
   elseif( alpha1 < alpha2 && alpha1 < alpha3 ) %Lmax is the smallest value, return
       result = [LMax phiLMax];
       return;
   else %start is the lowest value
       result = [start, starty];
       return;
   end
   iterator = iterator + 1;
end