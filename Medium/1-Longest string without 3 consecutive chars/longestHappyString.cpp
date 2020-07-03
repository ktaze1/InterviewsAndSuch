/*
A string is called happy if it does not have any of the strings 'aaa', 'bbb' or 'ccc' as a substring.

Given three integers a, b and c, return any string s, which satisfies following conditions:

s is happy and longest possible.
s contains at most a occurrences of the letter 'a', at most b occurrences of the letter 'b' and at most c occurrences of the letter 'c'.
s will only contain 'a', 'b' and 'c' letters.
If there is no such string s return the empty string "".

 

Example 1:

Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.
Example 2:

Input: a = 2, b = 2, c = 1
Output: "aabbc"
*/

#include <iostream>
#include <string>
#include <queue>

std::string longestDiverseString(int a, int b, int c) 
{
    //using max heap
    std::priority_queue<std::pair<int,char>>pq;
    if(a)
    pq.push({a,'a'});
    if(b)
    pq.push({b,'b'});
    if(c)
    pq.push({c,'c'});
    std::string ans="";
    while(pq.size()>1){
        std::pair<int,char>one = pq.top();pq.pop();
        std::pair<int,char>two = pq.top();pq.pop();
        
        ans+=std::string(one.first>=2? 2:1,one.second);
        one.first-=one.first>=2? 2:1;
        
        ans+=std::string((two.first>=2 && two.first>=one.first)? 2:1,two.second);
        two.first-=(two.first>=2 && two.first>=one.first)? 2:1;

        if(one.first>0) pq.push(one);
        if(two.first>0) pq.push(two);
    }
    
    if(pq.empty()) return ans;
    ans+=std::string(pq.top().first>=2? 2:1,pq.top().second);

    return ans;
}