// Last updated: 7/3/2026, 7:36:37 AM
1class Solution {
2public:
3    int findMaxPathScore(vector<vector<int>>& edges,
4                         vector<bool>& online,
5                         long long k) {
6
7        int n = online.size();
8
9        vector<vector<pair<int,int>>> adj(n);
10        vector<int> indeg(n);
11
12        int mxEdge = 0;
13
14        for (auto &e : edges) {
15            adj[e[0]].push_back({e[1], e[2]});
16            indeg[e[1]]++;
17            mxEdge = max(mxEdge, e[2]);
18        }
19
20        // Topological order
21        queue<int> q;
22        vector<int> topo;
23
24        for (int i = 0; i < n; i++)
25            if (indeg[i] == 0)
26                q.push(i);
27
28        while (!q.empty()) {
29            int u = q.front();
30            q.pop();
31
32            topo.push_back(u);
33
34            for (auto [v, c] : adj[u]) {
35                if (--indeg[v] == 0)
36                    q.push(v);
37            }
38        }
39
40        auto check = [&](int limit)->bool {
41
42            const long long INF = 4e18;
43
44            vector<long long> dist(n, INF);
45            dist[0] = 0;
46
47            for (int u : topo) {
48
49                if (dist[u] == INF)
50                    continue;
51
52                if (u != 0 && u != n-1 && !online[u])
53                    continue;
54
55                for (auto [v, c] : adj[u]) {
56
57                    if (c < limit)
58                        continue;
59
60                    if (v != n-1 && !online[v])
61                        continue;
62
63                    dist[v] = min(dist[v],
64                                  dist[u] + (long long)c);
65                }
66            }
67
68            return dist[n-1] <= k;
69        };
70
71        int lo = 0;
72        int hi = mxEdge;
73        int ans = -1;
74
75        while (lo <= hi) {
76
77            int mid = (lo + hi) / 2;
78
79            if (check(mid)) {
80                ans = mid;
81                lo = mid + 1;
82            }
83            else
84                hi = mid - 1;
85        }
86
87        return ans;
88    }
89};