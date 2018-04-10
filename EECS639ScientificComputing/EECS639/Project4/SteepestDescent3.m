function result = SteepestDescent3()

LMax = -1.2;
phiLMax = 1;
tempMx = LMax;
tempMy = phiLMax;

LMaxHalf = -.6;
phiLMaxHalf = 0.5;
tempHx = LMaxHalf;
tempHy = phiLMaxHalf;

start = -2;
starty = -2;
tempSx = start;
tempSy = starty;
alpha1 = 0;
alpha2 = 0;
alpha3 = 0;

iterator = 1;
while( iterator < 30 )
   for i=1:10
       alpha1 = 100*(tempMx^2-tempMy)^2+(tempMx-1)^2 + alpha1;
       alpha2 = 100*(tempHx^2-tempHy)^2+(tempHx-1)^2 + alpha2;
       alpha3 = 100*(tempSx^2-tempSy)^2+(tempSx-1)^2 + alpha3;
       tempMx = tempMx +1;
       tempMy = tempMy +1;
       tempHx = tempHx +1;
       tempHy = tempHy +1;
       tempSx = tempSx +1;
       tempSy = tempSy +1;
   end
   
   if( alpha2 < alpha1 && alpha2 < alpha3) %midpoint is lowest value
       if( alpha1 < alpha3) %LMax is less than start, move start and LMaxHalf
           start = LMaxHalf;
           starty = phiLMaxHalf;
           tempSx = start;
           tempSy = starty;
           
           LMaxHalf = (LMax - start)/2 + start;
           phiLMaxHalf = (phiLMax - starty)/2 + starty;
           tempHx = LMaxHalf;
           tempHy = phiLMaxHalf;
       else %start is less than LMax half, move LMax and LMax Half
           LMax = LMaxHalf;
           phiLMax = phiLMaxHalf;
           tempMx = LMax;
           tempMy = phiLMax;
           
           LMaxHalf = LMaxHalf/2;
           phiLMaxHalf = phiLMaxHalf/2;
           tempHx = LMaxHalf;
           tempHy = phiLMaxHalf;
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