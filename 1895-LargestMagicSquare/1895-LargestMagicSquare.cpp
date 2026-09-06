// Last updated: 9/6/2026, 3:58:43 PM
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> row(n,vector<int>(m+1,0)) , col(n+1,vector<int> (m,0));
    for(int i = 0 ; i < n; i++)
        for(int j = 0 ; j < m; j++){
            row[i][j+1] = row[i][j] + grid[i][j];
            col[i+1][j] = col[i][j] + grid[i][j];
        }   
    int mxSize = 1;
    for(int i = 0 ; i < n; i++)
        for(int j = 0 ; j < m; j++){
            for(int k = min(n-i, m-j); k>=1; k--){
                bool isMagic = 1;
                int sum = row[i][j+k] - row[i][j];
                // check the sum of rows
                for(int level = 0 ; level < k ; level++){
                    if(sum != row[i+level][j+k] - row[i+level][j])
                        {
                            isMagic = false;
                            break;
                        }
                }
                if(isMagic == false) continue;
                // check the sum of columns
                for(int level = 0 ; level < k ; level++){
                    if(sum != col[i+k][j+level] - col[i][j+level])
                        {
                            isMagic = false;
                            break;
                        }
                }
                if(isMagic == false) continue;
                //  check for diagonals
                int diag1 = 0 , diag2 = 0;
                for(int level = 0 ; level < k ; level++){
                    diag1+=grid[i+level][j+level];
                    diag2+=grid[i+level][j+k-level-1];
                }
                if(diag1 != sum || diag2 != sum) continue;
                if(isMagic) {
                    mxSize = max (mxSize , k);
                    break;
                }
            
            }
    }
    return mxSize;
}
};