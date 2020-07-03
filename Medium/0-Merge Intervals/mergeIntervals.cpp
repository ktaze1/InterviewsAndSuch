/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
*/

#include <iostream>
#include <vector>
#include <algorithm>


std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals)
{
    std::vector<std::vector<int>> result;

    std::sort(intervals.begin(), intervals.end(), [] (auto& a, auto& b) {
        return a[0] < b[0];
    });

    for(const auto& i : intervals){
        if(result.empty()) {result.push_back(i); continue;}

        auto& b = result.back();
        if(b[1]>=i[0]) b[1] = std::max(b[1],i[1]);
        else result.push_back(i);
    }
    return result;
}



int main()
{

}