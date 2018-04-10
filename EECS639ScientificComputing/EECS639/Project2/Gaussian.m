function result = Gaussian(data)

divisionkey = data(1,1);

dims = size(data,1);

if(dims<2)%termination condition for the recursion
    data(1,1)=1;
    result = data;
    return;
end

%divide everything in row 1 by first element
for i=1:dims
    data(1,i)=data(1,i)/divisionkey;
end

%reduce the rest of the column to zeroes
for i=2:dims
    data(i,:) = data(i,:)-data(i,1)*data(1,:);
end

%recursively solve the next row and column
%each iteration only solves 1 row and column
data(2:dims,2:dims)=Gaussian(data(2:dims,2:dims));

result = data;
   
        