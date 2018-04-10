function answers = ForwardSubstitutionPBands( data, p )

dims = size(data, 1); %size n of the matrix

answers = zeros( dims, 1);

answers(1) = data(1, 1); %this is the first x_n of our matrix


for i=2:1:dims
    accum = 0;
    if (i-p)<=0%handle the case where i is less than the number of bands
        for j=1:1:i%and we only have to check to i, not dims    
            accum = accum + data(i, j)*answers(j);
        end
    end
    if (i-p) > 0%handle the general case
        for j=i-p:1:dims
           accum = accum + data(i, j)*answers(j);
        end
    end
    answers(i)=accum*(-1)/data(i,i);%store result in answers
end

