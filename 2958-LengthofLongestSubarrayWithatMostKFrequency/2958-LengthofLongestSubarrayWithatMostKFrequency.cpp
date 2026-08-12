// Last updated: 8/13/2026, 1:16:29 AM
1class Solution {
2public:
3    int maxSubarrayLength(vector<int>& nums, int k) {
4        unordered_map<int,int> mp;
5        int n = nums.size() , ans = 0 , i = 0 , j = 0;
6        for(;i < n; i++){
7            mp[nums[i]]++;
8            ans = max(ans , i-j);
9            while(mp[nums[i]] > k && j < i){
10                mp[nums[j]]--;
11                j++;
12            }
13        }
14        ans = max(ans , i-j);
15        return ans;
16    }
17};