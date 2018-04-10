function answersLookup = ForwardSubstitution(data)

dims = size(data,1);%return size n of a matrix

answersLookup = zeros(dims,1);

answersLookup(1) = data(1,1);% return the n,nth value of a matrix

for i=2:1:dims
    accum = 0;
    for j=1:1:i-1%solving for numerator of generalized expression
        accum = accum + data(i,j)*answersLookup(j);%calcluate the summation
    end
    answersLookup(i)=accum*(-1)/data(i,i);%add the result to answers lookup
end
        