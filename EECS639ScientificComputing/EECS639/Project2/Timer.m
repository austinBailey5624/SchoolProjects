function [clockedF, clockedB] = Timer()

clockedF = zeros(1, 10);
clockedB = zeros(1, 10);
clockedBB = zeros(1, 10);
clockedBF = zeros(1, 10);
A = rand(1000, 1000);
B = rand(2000, 2000);
C = rand(3000, 3000);
D = rand(4000, 4000);
E = rand(5000, 5000);
F = rand(6000, 6000);
G = rand(7000, 7000);
H = rand(8000, 8000);
I = rand(9000, 9000);
J = rand(10000, 10000);


tic
ForwardSubstitutionPBands(A, 200);
clockedF(1) = toc;
tic
BackwardSubstitutionPBands(A, 200);
clockedB(1) = toc;

tic
ForwardSubstitutionPBands(B, 300);
clockedF(2) = toc;
tic
BackwardSubstitutionPBands(B, 300);
clockedB(2) = toc;

tic
ForwardSubstitutionPBands(C, 400);
clockedF(3) = toc;
tic
BackwardSubstitutionPBands(C, 400);
clockedB(3) = toc;

tic
ForwardSubstitutionPBands(D, 500);
clockedF(4) = toc;
tic
BackwardSubstitutionPBands(D, 500);
clockedB(4) = toc;

tic
ForwardSubstitutionPBands(E, 600);
clockedF(5) = toc;
tic
BackwardSubstitutionPBands(E, 600);
clockedB(5) = toc;

tic
ForwardSubstitutionPBands(F, 700);
clockedF(6) = toc;
tic
BackwardSubstitutionPBands(F, 700);
clockedB(6) = toc;

tic
ForwardSubstitutionPBands(G, 800);
clockedF(7) = toc;
tic
BackwardSubstitutionPBands(G, 800);
clockedB(7) = toc;

tic
ForwardSubstitutionPBands(H, 900);
clockedF(8) = toc;
tic
BackwardSubstitutionPBands(H, 900);
clockedB(8) = toc;

tic
ForwardSubstitutionPBands(I, 1000);
clockedF(9) = toc;
tic
BackwardSubstitutionPBands(I, 1000);
clockedB(9) = toc;

tic
ForwardSubstitutionPBands(J, 1100);
clockedF(10) = toc;
tic
BackwardSubstitutionPBands(J, 1100);
clockedB(10) = toc;

tic
ForwardSubstitutionMBlocks(A);
clockedBF(1) = toc;
tic
BackwardSubstitutionMBlocks(A);
clockedBB(1) = toc;

tic
ForwardSubstitutionMBlocks(B);
clockedBF(2) = toc;
tic
BackwardSubstitutionMBlocks(B);
clockedBB(2) = toc;

tic
ForwardSubstitutionMBlocks(C);
clockedBF(3) = toc;
tic
BackwardSubstitutionMBlocks(C);
clockedBB(3) = toc;

tic
ForwardSubstitutionMBlocks(D);
clockedBF(4) = toc;
tic
BackwardSubstitutionMBlocks(D);
clockedBB(4) = toc;

tic
ForwardSubstitutionMBlocks(E);
clockedBF(5) = toc;
tic
BackwardSubstitutionMBlocks(E);
clockedBB(5) = toc;

tic
ForwardSubstitutionMBlocks(F);
clockedBF(6) = toc;
tic
BackwardSubstitutionMBlocks(F);
clockedBB(6) = toc;

tic
ForwardSubstitutionMBlocks(G);
clockedBF(7) = toc;
tic
BackwardSubstitutionMBlocks(G);
clockedBB(7) = toc;

tic
ForwardSubstitutionMBlocks(H);
clockedBF(8) = toc;
tic
BackwardSubstitutionMBlocks(H);
clockedBB(8) = toc;

tic
ForwardSubstitutionMBlocks(I);
clockedBF(9) = toc;
tic
BackwardSubstitutionMBlockss(I);
clockedBB(9) = toc;

tic
ForwardSubstitutionMBlocks(J);
clockedBF(10) = toc;
tic
BackwardSubstitutionMBlockss(J);
clockedBB(10) = toc;


