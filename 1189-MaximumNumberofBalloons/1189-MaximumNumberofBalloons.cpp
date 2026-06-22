// Last updated: 6/22/2026, 3:48:12 AM
1class Solution {
2public:
3    int maxNumberOfBalloons(string text) {
4          map<char,int> mp;
5          string test = "balloon";
6          for(auto x:test) mp[x];
7          for(auto i :text) {
8            if(test.find(i) != string::npos) {
9              mp[i]++;
10            }
11          }
12        int mn = 1e9;
13        for(auto x:mp){
14          if(x.first == 'o' || x.first == 'l') mn = min(mn , x.second/2);
15          else mn = min(mn , x.second);
16        }
17        return mn;
18    }
19};