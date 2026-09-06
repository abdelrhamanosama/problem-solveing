// Last updated: 9/6/2026, 2:18:16 PM
class Solution {
struct DSU {
    vector<int> parent, sz , edges;

    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        edges.assign(n, 1e5);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    bool unite(int a, int b, int c) {
        a = find(a);
        b = find(b);
        edges[a] = min({c , edges[a] ,edges[b]});
        edges[b] = min({c , edges[a] ,edges[b]});
        if (a == b) return false;

        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];
        edges[a] = min({c , edges[a] ,edges[b]});

        return true;
    }

    int size(int x) {
        return sz[find(x)];
    }
    int get(int x) {
            return edges[find(x)];
    }
};

public:
    int minScore(int n, vector<vector<int>>& roads) {
       int mn =  1e9;
       DSU d(n+1);
       for(auto x:roads){
        auto u = x[0] , v = x[1] , c = x[2];
        d.unite(u,v,c); 
       }
       return d.get(1);
    }
};