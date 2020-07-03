/*
Given an integer n, return any array containing n unique integers such that they add up to 0.

 

Example 1:

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
*/

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

int main(){
    return 0;
}