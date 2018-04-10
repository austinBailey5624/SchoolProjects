function result = GaussianPartialPivot(data)

dims = size(data,1);

if(dims<2)
    data(1,1)=1;
    result = data;
    return;
end

max = data(1,1);
maxIndex = 1;

%find the maximum and the cooresponding index
for i=1:dims
    if(data(i,1) > max)
        max = data(i,1);
        disp(max);
        maxIndex = i;
    end
end

%switch the maximum and the first row
if(maxIndex~=1)
    temp = data(1,:);
    data(1,:)=data(maxIndex,:);
    data(maxIndex,:)=temp;
end

%divide everything in row 1 by first element
for i=1:dims
    data(1,i)=data(1,i)/data(1,1);
end

%reduce the rest of the column to zeroes
for i=2:dims
    data(i,:) = data(i,:)-data(i,1)*data(1,:);
end

data(2:dims,2:dims)=GaussianPartialPivot(data(2:dims,2:dims));
result = data;