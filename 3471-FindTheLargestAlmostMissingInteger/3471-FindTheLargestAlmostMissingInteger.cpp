// Last updated: 9/6/2026, 3:47:19 PM
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        int n = nums.size();

        unordered_map<int, int> windowCount;

        for (int l = 0; l + k <= n; l++) {

            unordered_set<int> seen;

            for (int i = l; i < l + k; i++) {
                seen.insert(nums[i]);
            }

            for (int x : seen) {
                windowCount[x]++;
            }
        }

        int ans = -1;

        for (auto& [x, cnt] : windowCount) {
            if (cnt == 1) {
                ans = max(ans, x);
            }
        }

        return ans;
    }
};