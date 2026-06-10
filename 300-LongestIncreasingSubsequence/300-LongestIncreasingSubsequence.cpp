// Last updated: 6/10/2026, 11:49:23 AM
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return dpIterative(nums);
    }
    int dpIterative(vector<int>& v) {
    int n = v.size();
    vector<int> dp(n, 1);
    int mx = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        mx = max(mx, dp[i]);
    }

    return mx;
}


};