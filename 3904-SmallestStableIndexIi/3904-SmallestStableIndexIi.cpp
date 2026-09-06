// Last updated: 9/6/2026, 2:12:06 PM
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> minValue(n);
        minValue[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            minValue[i] = min(minValue[i + 1], nums[i]);
        }

        int maxValue = 0;
        for (int i = 0; i < n; ++i) {
            maxValue = max(maxValue, nums[i]);
            if (maxValue - minValue[i] <= k) {
                return i;
            }
        }
        return -1;
    }
}; 