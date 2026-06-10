// Last updated: 6/10/2026, 11:49:42 AM
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> mp;
        int n = nums.size();
        for(int i = 0 ; i < min(k , n); i++){
            mp[nums[i]]++;
            if(mp[nums[i]] == 2)  return 1;
        }
        for(int i = k; i < nums.size(); i++){
            mp[nums[i]]++;
            if(mp[nums[i]] == 2)  return 1;
            mp[nums[i-k]]--;
        }
        return 0;
    }
};