#include <iostream>
#include <unordered_map>
#include <vector>


std::vector<int> twoSum(std::vector<int> &numbers, int target)
{
    std::unordered_map<int, int> hash;
    std::vector<int> result;

    for(auto i{0}; i < numbers.size(); i++){
        int numberToFind = target - numbers[i];

        if(hash.find(numberToFind) != hash.end()) {
            result.push_back(hash[numberToFind]);
            result.push_back(i);
            return result;
        }

        hash[numbers[i]] = i;
    }
    return result;
}


int main()
{

}
