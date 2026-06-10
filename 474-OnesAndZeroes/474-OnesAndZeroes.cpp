// Last updated: 6/10/2026, 11:48:58 AM
class Solution {
public:
    int mem[601][101][101];
    vector<pair<int,int>> X;
    int N;

    int dp(int idx, int m, int n) {
        if (idx == N) return 0;
        if (mem[idx][m][n] != -1) return mem[idx][m][n];

        int notTake = dp(idx + 1, m, n);
        int take = -1e9;
        int zeros = X[idx].first;
        int ones = X[idx].second;

        if (m >= zeros && n >= ones)
            take = 1 + dp(idx + 1, m - zeros, n - ones);

        return mem[idx][m][n] = max(take, notTake);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(mem, -1, sizeof(mem));
        for (auto& s : strs) {
            int zeros = 0, ones = 0;
            for (auto c : s)
                if (c == '0') zeros++;
                else ones++;
            X.push_back({zeros, ones});
        }
        N = X.size();
        return dp(0, m, n);
    }
};
