/*
    You are given with a string . Your task is to remove atmost two substrings of any length from the given string such that the remaining string contains vowels('a','e','i','o','u') only. Your aim is the maximise the length of the remaining string. Output the length of remaining string after removal of atmost two substrings.
NOTE: The answer may be 0, i.e. removing the entire string.

Sample Input
2
earthproblem
letsgosomewhere
Sample Output
3
2
*/

#include <iostream>
#include <vector>

class Solution{
public:
    int longestVowelString(std::string& str)
    {
        int start{0}, end{str.size()-1}, res {0}, count{0};

        std::vector<int> h;

        while(start <= end){ //count vowels from both start and end
            if(str[start] == 'a' || str[start] == 'e' || str[start] == 'i' || str[start] == 'o' || str[start] == 'u')
                ++start;
            else if(str[end] == 'a' || str[end] == 'e' || str[end] == 'i' || str[end] == 'o' || str[end] == 'u')
                --end;
            else break;
        }

        if (start>end) return str.size();
        for (auto i{0}; i<end; i++){
            
            if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') ++count;
            
            else{
                if(count>0) h.push_back(count);
                count = 0;
            }
        }

        end = str.size()-end-1;
        for(auto i{0}; i<h.size(); i++)
            res = std::max(res, std::max(end+h[i], start+h[i]+end));
        
        return res;
    }
};

int main()
{
    int t,n,h;
    std::string s1;
    Solution s=Solution();
    std::cin>>t;
    while(t--){  
     std::cin>>s1;
     int res=s.longestVowelString(s1);   
     std::cout<<res<<'\n';  
    }
    
}