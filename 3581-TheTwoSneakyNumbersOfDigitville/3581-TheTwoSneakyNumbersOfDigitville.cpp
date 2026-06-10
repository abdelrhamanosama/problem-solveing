// Last updated: 6/10/2026, 11:41:55 AM
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