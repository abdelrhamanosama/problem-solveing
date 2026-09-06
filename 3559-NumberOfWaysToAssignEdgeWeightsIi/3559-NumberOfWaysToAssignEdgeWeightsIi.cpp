// Last updated: 9/6/2026, 2:14:19 PM
class Solution {
    static const int N = 2e5 + 5;
    static const int LOG = 20;
    static const int MOD = 1e9 + 7;

    vector<int> adj[N];
    int up[N][LOG];
    int lvl[N];

    vector<vector<int>> mem;

    void dfs(int u, int p) {
        up[u][0] = p;
        lvl[u] = lvl[p] + 1;

        for (int j = 1; j < LOG; j++)
            up[u][j] = up[up[u][j - 1]][j - 1];

        for (int v : adj[u]) {
            if (v != p)
                dfs(v, u);
        }
    }

    void buildLCA(int root) {
        lvl[0] = -1;
        dfs(root, 0);
    }

    int kthAncestor(int u, int k) {
        for (int j = 0; j < LOG; j++) {
            if (k & (1 << j))
                u = up[u][j];
        }
        return u;
    }

    int LCA(int u, int v) {
        if (lvl[u] < lvl[v])
            swap(u, v);

        u = kthAncestor(u, lvl[u] - lvl[v]);

        if (u == v)
            return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

    int dist(int u, int v) {
        int l = LCA(u, v);
        return lvl[u] + lvl[v] - 2 * lvl[l];
    }

    int dp(int len, int parity) {

        if (len == 0)
            return parity == 1;

        int &ret = mem[len][parity];

        if (ret != -1)
            return ret;

        ret = (dp(len - 1, parity) + dp(len - 1, parity ^ 1)) % MOD;

        return ret;
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {

        int n = edges.size() + 1;

        for (int i = 0; i <= n; i++) {
            adj[i].clear();
            lvl[i] = 0;

            for (int j = 0; j < LOG; j++)
                up[i][j] = 0;
        }

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        buildLCA(1);

        mem.assign(n + 1, vector<int>(2, -1));

        vector<int> ans;

        for (auto &q : queries) {
            int d = dist(q[0], q[1]);
            int val = dp(d, 1);
            if(d)
                ans.push_back(val);
            else 
                ans.push_back(0);
        }

        return ans;
    }
};