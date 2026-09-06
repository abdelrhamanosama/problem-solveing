// Last updated: 9/6/2026, 2:15:35 PM
class Solution {

    struct DSU {
        vector<int> parent, sz;

        DSU(int n) {
            parent.resize(n);
            sz.assign(n, 1);
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int x) {
            if (x == parent[x])
                return x;
            return parent[x] = find(parent[x]);
        }

        bool same(int a, int b) { return find(a) == find(b); }

        bool unite(int a, int b) {
            a = find(a);
            b = find(b);

            if (a == b)
                return false;

            if (sz[a] < sz[b])
                swap(a, b);

            parent[b] = a;
            sz[a] += sz[b];

            return true;
        }

        int size(int x) { return sz[find(x)]; }
    };

public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        DSU d(n);
        vector<int> adj[n];
        vector<bool> visited(n, 0);
        for (auto& e : invocations) {
            d.unite(e[0], e[1]);
            adj[e[0]].push_back(e[1]);
        }
        // let's dfs on this DAG from k node to ensure to arrive to each node in
        // component
        queue<int> q;
        q.push(k);
        int cnt = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (visited[node])
                continue;
            visited[node] = 1;
            cnt++;
            for (auto x : adj[node]) {
                q.push(x);
            }
        }
        int leader = d.find(k);
        vector<int> ans;
        if (d.sz[leader] != cnt) {
            for (int i = 0; i < n; i++)
                ans.push_back(i);

        } else {
            for (int i = 0; i < n; i++)
                if (leader != d.find(i))
                    ans.push_back(i);
        }
        return ans;
    }
};