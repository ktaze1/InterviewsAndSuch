#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>


using namespace std;


string battleship(int n, string s, string t){
    string res="";
    
    vector<vector<char>> grid(n,vector<char>(n));
    vector<string> ships;
    set<string> hits;
    stringstream ss1(t);
    string substr;
    while(ss1 >> substr){
        hits.insert(substr);
    }
    stringstream ss2(s);
    string word;
    while(getline(ss2,word,',')){
        ships.push_back(word);
    }
    int ans2=0;
    int ans1=0;
    for(auto ship: ships){
        set<string> ship_coords;
        char topx=ship[0];
        char topy=ship[1];
        char bottomx=ship[3];
        char bottomy=ship[4];
        for(char i=topx;i<=bottomx;i++){
            for(char j=topy;j<=bottomy;j++){
                string pos="";
                pos+=i;
                pos+=j;
                ship_coords.insert(pos);
            }
        }
        if(includes(hits.begin(),hits.end(),ship_coords.begin(),ship_coords.end())){
            ans2++;
        }
        else{
            for(auto s:ship_coords){
                if(hits.find(s)!=hits.end()){
                    ans1++;
                    break;
                }
            }
        }
    }
    res+=to_string(ans1)+","+to_string(ans2);
    return res;
}
int main() {
    int n=4;
    string s="1B 2C,2D 4D";
    string t="2B 2D 3D 4D 4A";
    string ans=battleship(n,s,t);
    cout << ans << endl;
    return 0;
}