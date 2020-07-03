/**

Jack plays a game of battleships with his friend Stacy. The game is played on a square map of N
rows  numbered from 1 to N. Each row contains N cells, labeled with consecutive English upper-case
letters (A, B, C, etc.). Each cell is identified by a string composed of its row number followed by its
column number: for example, "9C" denotes the third cell in the 9th row, and "15D" denotes the
fourth cell in the 15th row.
Jack marks the positions of all his ships on the map (which is not shown to Stacy). Ships are defined
by rectangles with a maximum area of 4 cells. Stacy picks map cells to hit some ships. A ship is
considered to be hit if at least one of its constituent cells is hit. If all of a ship s cells are hit, the ship is
sunk.
The goal is to count the number of sunk ships and the number of ships that have been hit but not
sunk.

The positions of ships are given as a string S, containing pairs of positions describing respectively the
top-left and bottom-right corner cells of each ship. Ships descriptions are separated with commas.
The positions of hits are given as a string T, containing positions describing the map cells that were
hit: for the map in the example shown above, S = "1B 2C,2D 4D" and T = "2B 2D 3D 4D 4A". Ships in
S and hits in T may appear in any order.
Write a function:

class Solution { public String solution(int N, String S, String T); }

that, given the size of the map N and two strings S, T that describe the positions of ships and hits
respectively, returns a string with two numbers: the count of sunken ships and the count of ships that
have been hit but not sunk, separated with a comma.
For instance, given N = 4, S = "1B 2C,2D 4D" and T = "2B 2D 3D 4D 4A", your function should return
"1,1", as explained above.
Given N = 3, S = "1A 1B,2C 2C" and T = "1B", your function should return "0,1", because one ship
was hit but not sunk.
The positions of ships are given as a string S, containing pairs of positions describing respectively the
top-left and bottom-right corner cells of each ship. Ships' descriptions are separated with commas.
The positions of hits are given as a string T, containing positions describing the map cells that were
hit: for the map in the example shown above, S = "1B 2C,2D 4D" and T = "2B 2D 3D 4D 4A". Ships in
S and hits in T may appear in any order.
Write a function:

class Solution { public String solution(int N, String S, String T); }

that, given the size of the map N and two strings S, T that describe the positions of ships and hits
respectively, returns a string with two numbers: the count of sunken ships and the count of ships that
have been hit but not sunk, separated with a comma.

For instance, given N = 4, S = "1B 2C,2D 4D" and T = "2B 2D 3D 4D 4A", your function should return
"1,1", as explained above.

Given N = 3, S = "1A 1B,2C 2C" and T = "1B", your function should return "0,1", because one ship
was hit but not sunk.
**/

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