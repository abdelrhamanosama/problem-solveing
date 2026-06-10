// Last updated: 6/10/2026, 11:42:52 AM
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> g(m, vector<int>(n, 0)); 
        
        for(auto& x : walls) g[x[0]][x[1]] = 1; // wall = 1
        for(auto& x : guards) g[x[0]][x[1]] = 3; // guard = 3

        for(auto& x : guards) {
            int r = x[0], c = x[1];
            
            // up
            for(int i = r - 1; i >= 0 && g[i][c] != 1 && g[i][c] != 3; i--) 
                g[i][c] = 2;
            
            // down
            for(int i = r + 1; i < m && g[i][c] != 1 && g[i][c] != 3; i++) 
                g[i][c] = 2;
            
            // left
            for(int j = c - 1; j >= 0 && g[r][j] != 1 && g[r][j] != 3; j--) 
                g[r][j] = 2;
            
            // right
            for(int j = c + 1; j < n && g[r][j] != 1 && g[r][j] != 3; j++) 
                g[r][j] = 2;
        }

        int cnt = 0;
        for(int i = 0; i < m; i++) 
            for(int j = 0; j < n; j++) 
                if(g[i][j] == 0) cnt++;

        return cnt;
    }
};
