% Script P1B
clc
disp(' A  B  C  D  E  F      a     b     h      k      phi');
disp('-------------------------------------------------------');
for A = 0:1
   for B = 0:2
      for C = 0:2
         for D = [-1 1]
            for E = [-1 1]
               for F = [-1 1]
                  Kappa = MakeConic(A,B,C,D,E,F);
                  Eta = MakeEllipse(Kappa);
                  if ~isempty(Eta)
                     a = Eta.a; b = Eta.b; h = Eta.h; k = Eta.k; phi = Eta.phi; 
                    
                     s1 = sprintf('%2d %2d %2d %2d %2d %2d',A,B,C,D,E,F);
                     s2 = sprintf('%6.3f  %6.3f  %6.3f  %6.3f  %6.3f',a,b,h,k,phi);
 
                     disp([s1  '     ' s2])
                  end
               end
            end
         end
      end
   end 
end
