// Last updated: 9/6/2026, 2:17:24 PM
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = 0;

        for (int i = 0; i < n - 1; i++) {
             {
                for (int j = i + 1; j < n; j++) {
                    if (abs(nums[i] - nums[j]) <= target && dp[i] != -1) {
                        dp[j] = max(dp[j], dp[i] + 1);
                    }
                }
            } 
        }

        return dp[n - 1];
    }
};