// Last updated: 9/6/2026, 2:13:07 PM
class Solution
{
public:
    int maxPathScore(vector<vector<int>> &grid, int k)
    {
        int n = grid.size();
        int m = grid[0].size();

        const int NEG = -1e9;

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(m, vector<int>(k + 1, NEG))
        );

        int startCost = (grid[0][0] != 0);

        if (startCost > k)
            return -1;

        dp[0][0][startCost] = grid[0][0];

        int ans = -1;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                for (int c = 0; c <= k; c++) {

                    if (dp[i][j][c] == NEG)
                        continue;

                    // down
                    if (i + 1 < n) {

                        int nc = c + (grid[i + 1][j] != 0);

                        if (nc <= k) {
                            dp[i + 1][j][nc] = max(
                                dp[i + 1][j][nc],
                                dp[i][j][c] + grid[i + 1][j]
                            );
                        }
                    }

                    // right
                    if (j + 1 < m) {

                        int nc = c + (grid[i][j + 1] != 0);

                        if (nc <= k) {
                            dp[i][j + 1][nc] = max(
                                dp[i][j + 1][nc],
                                dp[i][j][c] + grid[i][j + 1]
                            );
                        }
                    }

                    if (i == n - 1 && j == m - 1)
                        ans = max(ans, dp[i][j][c]);
                }
            }
        }

        return ans;
    }
};