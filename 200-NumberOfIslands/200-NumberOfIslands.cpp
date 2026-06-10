// Last updated: 6/10/2026, 11:49:53 AM
struct DSU {

    vector<int> p;
    int comp = 0;

    DSU(int n) {
        p.resize(n);

        for (int i = 0; i < n; i++)
            p[i] = i;
    }

    int find(int u) {
        if (u == p[u])
            return u;

        return p[u] = find(p[u]);
    }

    void merge(int u, int v) {

        int l1 = find(u);
        int l2 = find(v);

        if (l1 == l2)
            return;

        p[l1] = l2;
        comp--;
    }
};

class Solution {
public:

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        DSU d(n * m);

        auto id = [&](int x, int y) {
            return x * m + y;
        };

        // count land cells
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == '1')
                    d.comp++;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (grid[i][j] == '0')
                    continue;

                // right
                if (j + 1 < m && grid[i][j + 1] == '1') {
                    d.merge(id(i,j), id(i,j+1));
                }

                // down
                if (i + 1 < n && grid[i + 1][j] == '1') {
                    d.merge(id(i,j), id(i+1,j));
                }
            }
        }

        return d.comp;
    }
};