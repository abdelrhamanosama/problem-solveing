// Last updated: 7/13/2026, 1:12:30 PM
1class Solution {
2#define all(s) s.begin(), s.end()
3
4public:
5    struct dsu {
6        vector<int> p, s;
7        dsu(int n) {
8
9            //   s = vector<int> (n , 1);
10            p = vector<int>(n, 1);
11            for (int i = 0; i < n; i++) {
12                p[i] = i;
13            }
14        }
15        int find(int u) {
16            if (u == p[u])
17                return u;
18            return p[u] = find(p[u]);
19        }
20        void merge(int u, int v) {
21            int l1 = find(u);
22            int l2 = find(v);
23
24            if (l1 == l2) {
25
26                return;
27            }
28            if (l1 > l2)
29                swap(l1, l2);
30            p[l2] = l1;
31            //   s[l1]+=s[l2];
32        }
33        bool is_connected(int u, int v) { return find(u) == find(v); }
34    };
35
36    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
37                                      vector<vector<int>>& queries) {
38        dsu d(n);
39        vector<pair<int, int>> v;
40        for (int i = 0; i < n; i++) {
41            v.push_back({nums[i], i});
42        }
43        sort(v.begin(), v.end());
44
45        for (int i = 1; i < n; i++) {
46            if (v[i].first - v[i - 1].first <= maxDiff)
47                d.merge(v[i].second, v[i - 1].second);
48        }
49        vector<bool> ans;
50        for (auto x : queries)
51            ans.push_back(d.is_connected(x[0], x[1]));
52        return ans;
53    }
54};