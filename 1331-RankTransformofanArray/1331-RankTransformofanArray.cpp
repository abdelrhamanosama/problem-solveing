// Last updated: 7/12/2026, 6:25:53 AM
1class Solution {
2#define all(s) s.begin(), s.end()
3
4public:
5vector<int> arrayRankTransform(vector<int>& arr) {
6      vector<int> ans;
7      set<int> s(all(arr));
8      map<int,int> mp;
9      int y = 1;
10      for(auto x:s)
11        mp[x] = y++;    
12      for(auto x:arr){
13        ans.push_back(mp[x]);
14      }
15      return ans;
16    }
17};