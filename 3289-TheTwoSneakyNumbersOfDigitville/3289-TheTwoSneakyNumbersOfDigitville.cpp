// Last updated: 9/6/2026, 2:15:32 PM
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        map<int,int> mp;
        for(auto x:nums) mp[x]++;
        vector<int> ans;
        for(auto x:mp)
            if(x.second == 2) ans.push_back(x.first);
    return ans;
    }
};