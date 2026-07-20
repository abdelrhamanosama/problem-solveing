// Last updated: 7/20/2026, 6:23:40 PM
1class Solution {
2public:
3    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
4      int n = grid.size() , m = grid[0].size();
5      vector<vector<int>> g(n,vector<int>(m,0));
6      k%=(n*m);
7      for(int i = 0; i < n; i++)
8        for(int j = 0 ; j <m; j++){
9            int x = (i)*m + j + k;
10            x%=(n*m);
11            int y = x%m;
12            int z = x/m;
13            g[z][y] = grid[i][j];
14        } 
15        return g;   
16    }
17};