// Last updated: 9/6/2026, 2:18:22 PM
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();

        // dp[i][j][mod]
        vector dp(n, vector(m, vector<int>(k, 0)));

        dp[0][0][grid[0][0] % k] = 1;
        int Mod = 1e9 + 7;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int mod=0; mod<k; mod++){

                    if(i==0 && j==0) continue;
                    int newMod = (mod + grid[i][j]) % k;

                    if(i > 0)
                        dp[i][j][newMod] += dp[i-1][j][mod];

                    if(j > 0)
                        dp[i][j][newMod] += dp[i][j-1][mod];
                    dp[i][j][newMod] %= Mod; 
                }
            }
        }

        return dp[n-1][m-1][0];
    }
};
