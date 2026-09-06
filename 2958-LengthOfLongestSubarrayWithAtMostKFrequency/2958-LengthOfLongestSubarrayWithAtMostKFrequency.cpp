// Last updated: 9/6/2026, 2:16:33 PM
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size() , ans = 0 , i = 0 , j = 0;
        for(;i < n; i++){
            mp[nums[i]]++;
            ans = max(ans , i-j);
            while(mp[nums[i]] > k && j < i){
                mp[nums[j]]--;
                j++;
            }
        }
        ans = max(ans , i-j);
        return ans;
    }
};