function [X_outer, Y_outer] = XY_Outer( a, b, n, angles)

angles_2 = angles( 2 : n+1 );
angles_2(n+1) = angles(1);

X_outer = a* ((sin(angles) - sin(angles_2))/(sin(angles)*cos(angles_2) - cos(angles)*sin(angles_2)));
Y_outer = b* ((cos(angles_2) - cos(angles))/(sin(angles)*cos(angles_2) - cos(angles)*sin(angles_2)));