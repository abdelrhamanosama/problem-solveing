// Last updated: 9/6/2026, 2:20:05 PM
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& v) {
        int n = v.size();
        sort(v.begin(), v.end()); // sort by start time

        vector<int> best(n);
        best[n-1] = v[n-1][2];
        for (int i = n - 2; i >= 0; i--)
            best[i] = max(best[i + 1], v[i][2]);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int l = i + 1, r = n - 1, pos = n;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (v[mid][0] > v[i][1]) {
                    pos = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            ans = max(ans, v[i][2]);
            if (pos < n)
                ans = max(ans, v[i][2] + best[pos]);
        }
        return ans;
    }
};
