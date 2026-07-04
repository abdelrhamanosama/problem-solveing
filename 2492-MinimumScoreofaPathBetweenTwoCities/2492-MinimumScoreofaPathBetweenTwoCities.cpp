// Last updated: 7/4/2026, 11:56:27 AM
1class Solution {
2struct DSU {
3    vector<int> parent, sz , edges;
4
5    DSU(int n) {
6        parent.resize(n);
7        sz.assign(n, 1);
8        edges.assign(n, 1e5);
9        iota(parent.begin(), parent.end(), 0);
10    }
11
12    int find(int x) {
13        if (x == parent[x]) return x;
14        return parent[x] = find(parent[x]);
15    }
16
17    bool same(int a, int b) {
18        return find(a) == find(b);
19    }
20
21    bool unite(int a, int b, int c) {
22        a = find(a);
23        b = find(b);
24        edges[a] = min({c , edges[a] ,edges[b]});
25        edges[b] = min({c , edges[a] ,edges[b]});
26        if (a == b) return false;
27
28        if (sz[a] < sz[b])
29            swap(a, b);
30
31        parent[b] = a;
32        sz[a] += sz[b];
33        edges[a] = min({c , edges[a] ,edges[b]});
34
35        return true;
36    }
37
38    int size(int x) {
39        return sz[find(x)];
40    }
41    int get(int x) {
42            return edges[find(x)];
43    }
44};
45
46public:
47    int minScore(int n, vector<vector<int>>& roads) {
48       int mn =  1e9;
49       DSU d(n+1);
50       for(auto x:roads){
51        auto u = x[0] , v = x[1] , c = x[2];
52        d.unite(u,v,c); 
53       }
54       return d.get(1);
55    }
56};