// Last updated: 8/4/2026, 5:37:26 AM
1class Solution {
2public:
3    vector<int> findMissingElements(vector<int>& nums) {
4        vector<int> ans;
5        sort(nums.begin() ,nums.end());
6        int mn = nums[0] , mx = nums.back();
7        for(int i = mn+1 ; i < mx ; i++)
8            if(!binary_search(nums.begin() ,nums.end() , i)) ans.push_back(i);
9        return ans;
10    }
11};