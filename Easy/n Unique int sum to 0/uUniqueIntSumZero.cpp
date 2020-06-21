#include <iostream>
#include <vector>


std::vector<int> uniqueIntSumZero(int n)
{
    std::vector<int> result;
    int i;
    for(i = 1; i<=n/2; i++)
        result.push_back(i);
    
    for(i--; i>0; i--)
        result.push_back(-i);

    if(result.size() < n)
        result.push_back(0);

    return result;
}