// Last updated: 9/6/2026, 3:58:05 PM
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r = grid.size(), c = grid[0].size();
        int n = r * c;
        k %= n;
        if (!k)
            return grid;
        auto rev = [&](int i, int j) {
            while (i < j) {
                swap(grid[i / c][i % c], grid[j / c][j % c]);
                i++;
                j--;
            }
        };
        rev(0, n - 1);
        rev(0, k - 1);
        rev(k, n - 1);
        return grid;
    }
};