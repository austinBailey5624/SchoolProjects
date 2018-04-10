function result = SteepestDescent(startingPoint,LMax)

AlphaK = LMax;
result{0} = startingPoint;

%forty iterations max - arbitrary
iterator = 1;
while(iterator<41 && ~(result{iterator} == result{iteratior-1} ))
   if %minimum is less than Lmax
       if%minimum is less than Lmax/2
          return; 
       else%minimum is greater than Lmax/2
           %add Lmax/2, update AlphaK
           %result = [result; AlphaK/2, f(AlphaK/2)]%Note: this doesnt work
           %because we're in 2d
       end
   else %Lmax is less than minimum
       if%Lmax is less than Lmax/2
           %we're already at the minimum, return
           return;
       else%Lmax/2 is less than Lmax
           %add Lmax/2, update AlphaK
           %result = [result; AlphaK/2, f(AlphaK/2)]%Note: this doesnt work
           %because we're in 2d
       end
   end
   iterator = iterator + 1;
end