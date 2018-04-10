function answers = BackwardSubstitutionPBands(data,p)

dims = size(data,1);

answers = zeros(dims,1);

answers(dims) = data(dims,dims);% return the n,nth value of a matrix

for i=(dims-1):-1:1
    accum = 0;
    for j=dims:-1:p%solving for numerator of generalized expression
        accum = accum + data(i,j)*answers(j);%Only go to p since that is the maximum number of bands we need to check
    end
    answers(i)=accum*(-1)/data(i,i);
end