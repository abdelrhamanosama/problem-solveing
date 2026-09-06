// Last updated: 9/6/2026, 2:14:15 PM
class Solution {
private:
    static const int MOD = 1e9 + 7;

    vector<vector<int>> adj;
    vector<vector<int>> mem;

    int dfs(int u, int p) {
        int depth = 0;

        for (int v : adj[u]) {
            if (v == p) continue;

            depth = max(depth, 1 + dfs(v, u));
        }

        return depth;
    }

    int dp(int val, int parity) {

        if (val < 0)
            return 0;

        if (val == 0)
            return (parity == 1);

        int &ret = mem[val][parity];

        if (ret != -1)
            return ret;

        long long ans = 0;

        ans += dp(val - 1, (parity + 1) & 1);
        ans += dp(val - 1, (parity + 2) & 1);

        return ret = ans % MOD;
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {

        int n = edges.size() + 1;

        adj.assign(n + 1, {});

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int depth = dfs(1, -1);

        mem.assign(depth + 1, vector<int>(2, -1));

        return dp(depth, 0);
    }
};