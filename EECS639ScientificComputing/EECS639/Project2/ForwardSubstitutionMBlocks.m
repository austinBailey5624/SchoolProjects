function result = ForwardSubstitutionMBlocks(data)
temp =LUFactorizationForL(data);
result  = ForwardSubstitution(temp);