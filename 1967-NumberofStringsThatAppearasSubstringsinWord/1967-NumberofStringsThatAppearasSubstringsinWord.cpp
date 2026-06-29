// Last updated: 6/29/2026, 3:29:09 AM
1class Solution {
2public:
3    
4int numOfStrings(vector<string>& patterns, string word) {
5        int cnt = 0;
6        for(auto x: patterns){
7          if(word.find(x) != string::npos) cnt++;
8        }
9        return cnt;
10    }
11};