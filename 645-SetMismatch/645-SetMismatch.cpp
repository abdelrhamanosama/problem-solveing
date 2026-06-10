// Last updated: 6/10/2026, 11:48:17 AM
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        vector<int> ans;
        for(int i = 0 ; i < n; i++) mp[nums[i]]++;
        int f1 = 0 , f2 = 0;
        for(int i = 1 ; i <= n ;i++){
            if(mp[i] == 0) f2 = i;
            if(mp[i] == 2) f1 = i;
        }
        ans.push_back(f1);
        ans.push_back(f2);
        return ans;
    }
};