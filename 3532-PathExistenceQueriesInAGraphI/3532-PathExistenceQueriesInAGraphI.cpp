// Last updated: 9/6/2026, 2:14:21 PM
class Solution {
#define all(s) s.begin(), s.end()

public:
    struct dsu {
        vector<int> p, s;
        dsu(int n) {

            //   s = vector<int> (n , 1);
            p = vector<int>(n, 1);
            for (int i = 0; i < n; i++) {
                p[i] = i;
            }
        }
        int find(int u) {
            if (u == p[u])
                return u;
            return p[u] = find(p[u]);
        }
        void merge(int u, int v) {
            int l1 = find(u);
            int l2 = find(v);

            if (l1 == l2) {

                return;
            }
            if (l1 > l2)
                swap(l1, l2);
            p[l2] = l1;
            //   s[l1]+=s[l2];
        }
        bool is_connected(int u, int v) { return find(u) == find(v); }
    };

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        dsu d(n);
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());

        for (int i = 1; i < n; i++) {
            if (v[i].first - v[i - 1].first <= maxDiff)
                d.merge(v[i].second, v[i - 1].second);
        }
        vector<bool> ans;
        for (auto x : queries)
            ans.push_back(d.is_connected(x[0], x[1]));
        return ans;
    }
};