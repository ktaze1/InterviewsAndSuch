/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
#include <iostream>
#include <vector>



std::vector<int> twoSum(std::vector<int>& nums, int target){
    std::vector<int> result;
    
    for(auto i{0}; i<nums.size() -1; i++){
        for(auto j{1}; j<nums.size(); j++){
            if(nums[i] + nums[j] == target){
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
    return result;
}


int main()
{
    std::vector<int> answer {0};
    std::vector<int> test{2,7,11,15};
    answer = twoSum(test, 26);
    for(int i{0}; i < answer.size(); i++){
        std::cout << answer[i];
    }
    return 0;
}