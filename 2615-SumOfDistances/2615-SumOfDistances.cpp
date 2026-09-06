// Last updated: 9/6/2026, 2:17:35 PM
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);

        unordered_map<int, long long> cnt, sum;

        // left pass
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            ans[i] += cnt[x] * i - sum[x];
            cnt[x]++;
            sum[x] += i;
        }

        cnt.clear();
        sum.clear();

        // right pass
        for (int i = n - 1; i >= 0; i--) {
            int x = nums[i];
            ans[i] += sum[x] - cnt[x] * i;
            cnt[x]++;
            sum[x] += i;
        }

        return ans;
    }
};