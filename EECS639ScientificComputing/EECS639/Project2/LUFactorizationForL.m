function result = LUFactorizationForL(data)

divisionkey = data(1,1);

dims = size(data,1);

%add 1's along the diagonal of L
result(1,1)=1;

if(dims<2)
    return;
end

%load the info for this subcolumn
for i=1:dims
    result(i,1) = data(i,1)/divisionkey;
end

for i=2:dims
    data(i,:) = data(i,:)-data(i,1)*data(1,:);%reduce the ith row by the first value in that row times that row
end

%Each iteraion only solves the leftmost column and top row,
%Recurse to solve the rest
result(2:dims,2:dims) = LUFactorizationForL(data(2:dims,2:dims));
