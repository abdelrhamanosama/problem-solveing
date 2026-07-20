// Last updated: 7/20/2026, 6:37:12 PM
1class Solution {
2public:
3    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
4        int r = grid.size(), c = grid[0].size();
5        int n = r * c;
6        k %= n;
7        if (!k)
8            return grid;
9        auto rev = [&](int i, int j) {
10            while (i < j) {
11                swap(grid[i / c][i % c], grid[j / c][j % c]);
12                i++;
13                j--;
14            }
15        };
16        rev(0, n - 1);
17        rev(0, k - 1);
18        rev(k, n - 1);
19        return grid;
20    }
21};