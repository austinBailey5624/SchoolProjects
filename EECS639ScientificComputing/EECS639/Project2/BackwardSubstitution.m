function answersLookup = BackwardSubstitution(data)

dims = size(data,1);%return size n of a matrix

answersLookup = zeros(dims,1);

answersLookup(dims) = data(dims,dims);% return the n,nth value of a matrix

for i=(dims-1):-1:1
    accum = 0;%The accumulator stores the information
    for j=dims:-1:i%solving for numerator of generalized expression
        accum = accum + data(i,j)*answersLookup(j);
    end
    answersLookup(i)=accum*(-1)/data(i,i);
end
        