// Last updated: 9/6/2026, 2:17:04 PM
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
      int n = grid.size() , m = grid[0].size();
      int dx [] = {1,-1,0,0};
      int dy [] = {0,0,1,-1};
      vector<vector<int>> dist(n ,vector<int> (m , 1e9));    
      queue<array<int,2>> q;
      for(int i = 0 ; i < n; i++) 
        for(int j = 0 ; j < m; j++)
          if(grid[i][j] == 1) {
            q.push({i,j});
            dist[i][j] = 0;
          }
      while(!q.empty()) {
        auto [x,y] = q.front(); 
        q.pop();
        for(int k = 0 ; k < 4 ; k++){
          int i = x+dx[k];
          int j = y+dy[k];
          if(i < 0 || j < 0 || i >= n || j >= m) continue;
          if(dist[i][j] != 1e9) continue;
          dist[i][j] = dist[x][y] + 1;
          q.push({i,j});
        }
      }
      priority_queue<array<int,3>>pq;
      vector<vector<int>> best(n, vector<int>(n, -1));
      pq.push({dist[0][0] , 0 ,0 });
      best[0][0] = dist[0][0];
      while(!pq.empty()){
        auto [c,x,y] = pq.top();
        pq.pop();
        if(x == n-1 && y == m-1) return c;
        if(c < best[x][y]) continue;
        for(int k = 0 ; k <4 ; k++)
          {
            int i = x+dx[k];
            int j = y+dy[k];
            if(i < 0 || j < 0 || i >= n || j >= m) continue;
            int nc = min(dist[i][j] , c);
            if(nc > best[i][j])
            {
                best[i][j] = nc;
                pq.push({nc,i,j});
            }
          }
      }
      return 0;
    }
};