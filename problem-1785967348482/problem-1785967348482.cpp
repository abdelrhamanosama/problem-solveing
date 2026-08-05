// Last updated: 8/6/2026, 1:02:28 AM
1class Solution {
2
3    struct DSU {
4        vector<int> parent, sz;
5
6        DSU(int n) {
7            parent.resize(n);
8            sz.assign(n, 1);
9            iota(parent.begin(), parent.end(), 0);
10        }
11
12        int find(int x) {
13            if (x == parent[x])
14                return x;
15            return parent[x] = find(parent[x]);
16        }
17
18        bool same(int a, int b) { return find(a) == find(b); }
19
20        bool unite(int a, int b) {
21            a = find(a);
22            b = find(b);
23
24            if (a == b)
25                return false;
26
27            if (sz[a] < sz[b])
28                swap(a, b);
29
30            parent[b] = a;
31            sz[a] += sz[b];
32
33            return true;
34        }
35
36        int size(int x) { return sz[find(x)]; }
37    };
38
39public:
40    vector<int> remainingMethods(int n, int k,
41                                 vector<vector<int>>& invocations) {
42        DSU d(n);
43        vector<int> adj[n];
44        vector<bool> visited(n, 0);
45        for (auto& e : invocations) {
46            d.unite(e[0], e[1]);
47            adj[e[0]].push_back(e[1]);
48        }
49        // let's dfs on this DAG from k node to ensure to arrive to each node in
50        // component
51        queue<int> q;
52        q.push(k);
53        int cnt = 0;
54        while (!q.empty()) {
55            int node = q.front();
56            q.pop();
57            if (visited[node])
58                continue;
59            visited[node] = 1;
60            cnt++;
61            for (auto x : adj[node]) {
62                q.push(x);
63            }
64        }
65        int leader = d.find(k);
66        vector<int> ans;
67        if (d.sz[leader] != cnt) {
68            for (int i = 0; i < n; i++)
69                ans.push_back(i);
70
71        } else {
72            for (int i = 0; i < n; i++)
73                if (leader != d.find(i))
74                    ans.push_back(i);
75        }
76        return ans;
77    }
78};