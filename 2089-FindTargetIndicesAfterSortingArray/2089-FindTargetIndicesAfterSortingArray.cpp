// Last updated: 10/19/2026, 9:33:56 PM
1class Solution {
2public:
3    vector<int> targetIndices(vector<int>& nums, int target) {
4        sort(nums.begin() , nums.end());
5        vector<int> ans;
6        for(int i = 0 ; i < nums.size(); i++){
7            if(target == nums[i]) ans.push_back(i);
8        }
9        return ans;
10    }
11};