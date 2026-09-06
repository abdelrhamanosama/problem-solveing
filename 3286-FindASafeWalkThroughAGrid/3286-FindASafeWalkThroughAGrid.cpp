// Last updated: 9/6/2026, 2:15:36 PM
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
      int n = grid.size() , m = grid[0].size();
      int dx [] = {1,-1,0,0};
      int dy [] = {0,0,1,-1};
      queue<array<int,3>>pq;
      vector<vector<int>> best(n,vector<int>(m,-1));
      if(grid[0][0] == 1) health--;
      pq.push({health , 0 ,0});
      best[0][0] = health;
      while(!pq.empty()){
        auto [c,x,y] = pq.front();pq.pop();
        if(x == n-1 && y == m-1 && c >= 1) return 1;
        if(c < best[x][y]) continue;
        for(int k = 0 ; k < 4 ; k++){
          int i = dx[k] + x;
          int j = dy[k] + y;
          if(i < 0 || j < 0 || i >= n || j >= m) continue;
          int nc = c + (grid[i][j] ? -1 : 0);
          if(nc > best[i][j]) {
            best[i][j] = nc;
            pq.push({nc,i,j});
          }
        }
      }
      return 0;
    }
};