function New_Kappa = RotateConic(Kappa,phi)
c = cos(phi);
s = sin(phi);

aa = Kappa.A*(c.^2) - Kappa.B*c*s + Kappa.C*(s.^2);
%bb = s*(2*Kappa.A*c - Kappa.B*s + 2*Kappa.C*c);
bb = 2*Kappa.A*c*s + Kappa.B*c.^2 - Kappa.B*s.^2 - 2*Kappa.C*s*c;
cc = Kappa.A*s*s + Kappa.B*c*s + Kappa.C*c*c;
dd = Kappa.D*c - Kappa.E*s;
ee = Kappa.D*s + Kappa.E*c;
ff = Kappa.F;

New_Kappa = MakeConic(aa,bb,cc,dd,ee,ff);
end