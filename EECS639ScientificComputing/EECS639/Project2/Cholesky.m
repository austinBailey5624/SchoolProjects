function result = Cholesky(data)

dims = size(data,1);

result = zeros(dims,dims);

if dims==1
    result(1,1)=sqrt(data(1,1));
    return;
end


for i=1:dims
    for j=1:dims
        summation=0;
        if(i<j)%if we are beneath the diagonal, there should only be zeroes
            result(i,j)=0;%Since Cholesky returns upper triangular
        end
        if(j==i)
            for k=1:(j-1)%solve for the summation in the formula where j==i
                summation = summation + (result(j,k)*result(j,k));
            end
            result(i,j) = sqrt(data(i,j)-summation);%store the result
        end
        if(i>j)
            for k=1:(j-1)%solve for the summation in the formula where j<i
                summation = summation + result(i,k)*result(j,k); 
            end
            result(i,j) = (1/result(j,j))*(data(i,j)-summation);%store the result
        end
    end
end

result = result*transpose(result);%Multiply by the transpose to get the final result


            
        