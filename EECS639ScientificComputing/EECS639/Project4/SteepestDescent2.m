function result = SteepestDescent2()

LMax = -1.2;
phiLMax = 1;

LMaxHalf = -.6;
phiLMaxHalf = 0.5;

start = -2;
starty = -2;

iterator = 1;
while( iterator < 30 )
   alpha1 = (1-LMax)^2 + 100*(phiLMax-LMax^2)^2;
   alpha2 = (1-LMaxHalf)^2 + 100*(phiLMaxHalf-LMaxHalf^2)^2;
   alpha3 = (1-start)^2 + 100*(starty-start^2)^2;
   
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