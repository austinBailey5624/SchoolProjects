function [C_inner, C_outer] = Eperimeter(a, b, n)
angles = gimmeAngles( n );

C_inner = symsum(sqrt((a*cos(angles(k)) - a*cos(angles(k-1))).^2 + ( b*sin(angles(k)) - b*sin(angles(k-1))).^2 ), k, 2, n+1 );

[X_Outer, Y_Outer] = XY_Outer( a, b, n, angles);

C_outer = symsum(sqrt((X_Outer(k) - X_Outer(k-1)).^2 + (Y_Outer(k) - Y_Outer(k-1)).^2), k, 2, n+1);
