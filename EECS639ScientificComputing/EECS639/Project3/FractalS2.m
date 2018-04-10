colormap = blanks(22500); %char array for colors
k = 1; %just a counter
l = 1;
z = zeros(1, 22500); %complex points


x=linspace(.5,.6,150);
y=linspace(-.1,.1,150);
root1 = complex(1,.4);
for i=1:150
    for j=1:150
       z(k) =  complex(x(i), y(j));
       %disp(z(k));
       if(k<2)
          l=k;
       else
           l=k-1;
       end
       colormap(k) = Secant2(z(l),z(k));
       %colormap(k) = Secant2(root1,z(k)); %using Secant method to fill colormap
       k = k+1;
    end
end

for i=1:22500 %drawing the actual fractal
    plot(z(i), 'color', colormap(i), 'marker', '.');
    hold on;
end
