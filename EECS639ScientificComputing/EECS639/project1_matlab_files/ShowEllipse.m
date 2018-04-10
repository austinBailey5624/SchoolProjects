function ShowEllipse(Eta)
%center = [Eta.h, Eta.k];
%verticalStrech = sqrt(Eta.a);
%$horizStrech = Eta.b;
%Plots a hundred data points in the x direction
%x = Eta.h-horizStrech:horizStrech/50:Eta.h+horizStrech;
%y=(sqrt(((x-Eta.h)/(Eta.a*Eta.b)).^2))+Eta.k;
%{
t=linspace(0,2*pi)
x=Eta.a*cos(t);
y=Eta.b*sin(t);
plot(x,y);
%}
x=(Eta.h-Eta.a:Eta.a/50:Eta.h+Eta.a);
y = Eta.b * sqrt(1 - (((x-Eta.h)/Eta.a).^2) ) + Eta.k;
y2= -(Eta.b * sqrt(1 - (((x - Eta.h)/Eta.a).^2) )) + Eta.k;
plot(x,y,'color','r'); hold on;
plot(x,y2,'color','b');