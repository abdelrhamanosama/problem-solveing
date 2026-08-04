// Last updated: 8/4/2026, 5:59:06 AM
1class Solution {
2    static const int N = 2e5 + 5;
3    static const int LOG = 20;
4    static const int MOD = 1e9 + 7;
5
6    vector<int> adj[N];
7    int up[N][LOG];
8    int lvl[N];
9
10    vector<vector<int>> mem;
11
12    void dfs(int u, int p) {
13        up[u][0] = p;
14        lvl[u] = lvl[p] + 1;
15
16        for (int j = 1; j < LOG; j++)
17            up[u][j] = up[up[u][j - 1]][j - 1];
18
19        for (int v : adj[u]) {
20            if (v != p)
21                dfs(v, u);
22        }
23    }
24
25    void buildLCA(int root) {
26        lvl[0] = -1;
27        dfs(root, 0);
28    }
29
30    int kthAncestor(int u, int k) {
31        for (int j = 0; j < LOG; j++) {
32            if (k & (1 << j))
33                u = up[u][j];
34        }
35        return u;
36    }
37
38    int LCA(int u, int v) {
39        if (lvl[u] < lvl[v])
40            swap(u, v);
41
42        u = kthAncestor(u, lvl[u] - lvl[v]);
43
44        if (u == v)
45            return u;
46
47        for (int j = LOG - 1; j >= 0; j--) {
48            if (up[u][j] != up[v][j]) {
49                u = up[u][j];
50                v = up[v][j];
51            }
52        }
53
54        return up[u][0];
55    }
56
57    int dist(int u, int v) {
58        int l = LCA(u, v);
59        return lvl[u] + lvl[v] - 2 * lvl[l];
60    }
61
62    int dp(int len, int parity) {
63
64        if (len == 0)
65            return parity == 1;
66
67        int &ret = mem[len][parity];
68
69        if (ret != -1)
70            return ret;
71
72        ret = (dp(len - 1, parity) + dp(len - 1, parity ^ 1)) % MOD;
73
74        return ret;
75    }
76
77public:
78    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
79                                  vector<vector<int>>& queries) {
80
81        int n = edges.size() + 1;
82
83        for (int i = 0; i <= n; i++) {
84            adj[i].clear();
85            lvl[i] = 0;
86
87            for (int j = 0; j < LOG; j++)
88                up[i][j] = 0;
89        }
90
91        for (auto &e : edges) {
92            int u = e[0];
93            int v = e[1];
94
95            adj[u].push_back(v);
96            adj[v].push_back(u);
97        }
98
99        buildLCA(1);
100
101        mem.assign(n + 1, vector<int>(2, -1));
102
103        vector<int> ans;
104
105        for (auto &q : queries) {
106            int d = dist(q[0], q[1]);
107            int val = dp(d, 1);
108            if(d)
109                ans.push_back(val);
110            else 
111                ans.push_back(0);
112        }
113
114        return ans;
115    }
116};