// Last updated: 9/7/2026, 2:32:17 AM
1class Solution {
2public:
3    int maxProduct(vector<int>& nums) {
4        int mx = -1e9 , n = nums.size();
5        for(int i = 0 ; i < n; i++)
6            {
7                int prod = 1;
8                for(int j = i; j<n; j++){
9                    prod*=nums[j];
10                    mx = max(mx , prod);
11                }
12            }
13        return mx;
14    }
15};