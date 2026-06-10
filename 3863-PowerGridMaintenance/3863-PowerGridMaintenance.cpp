// Last updated: 6/10/2026, 11:41:32 AM
class Solution {
public:
    struct DSU {
    vector<int> p, sz;
    vector<set<int>> mx;
    vector<bool> deleted;

    DSU(int n) {
        p.resize(n + 1);
        sz.assign(n + 1, 1);
        mx.resize(n + 1);
        deleted.assign(n + 1, true);
        for (int i = 1; i <= n; i++) {
            p[i] = i;
            mx[i].insert(i);
        }
    }

    int find(int u) {
        return p[u] == u ? u : p[u] = find(p[u]);
    }

    void merge(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return;
        if (sz[u] > sz[v]) swap(u, v);
        for (int x : mx[u]) mx[v].insert(x);
        mx[u].clear();
        sz[v] += sz[u];
        p[u] = v;
    }

    void remove(int val) {
        if (!deleted[val]) return;
        int r = find(val);
        mx[r].erase(val);
        deleted[val] = false;
    }

    int get(int val) {
        if (deleted[val]) return val;
        int r = find(val);
        if (mx[r].empty()) return -1;
        return *mx[r].begin();
    }
};


    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU d(c);
        for (auto& x : connections)
            d.merge(x[0], x[1]);

        vector<int> ans;
        for (auto& q : queries) {
            int op = q[0], y = q[1];
            if (op == 1)
                ans.push_back(d.get(y));
            else
                d.remove(y);
        }
        return ans;
    }
};
