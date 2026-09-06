// Last updated: 9/6/2026, 3:59:36 PM
class Solution {
#define all(s) s.begin(), s.end()

public:
vector<int> arrayRankTransform(vector<int>& arr) {
      vector<int> ans;
      set<int> s(all(arr));
      map<int,int> mp;
      int y = 1;
      for(auto x:s)
        mp[x] = y++;    
      for(auto x:arr){
        ans.push_back(mp[x]);
      }
      return ans;
    }
};