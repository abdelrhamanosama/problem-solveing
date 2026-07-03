// Last updated: 7/3/2026, 6:26:18 AM
1class Solution {
2public:
3    bool findSafeWalk(vector<vector<int>>& grid, int health) {
4      int n = grid.size() , m = grid[0].size();
5      int dx [] = {1,-1,0,0};
6      int dy [] = {0,0,1,-1};
7      priority_queue<array<int,3>>pq;
8      vector<vector<int>> best(n,vector<int>(m,-1));
9      if(grid[0][0] == 1) health--;
10      pq.push({health , 0 ,0});
11      best[0][0] = health;
12      while(!pq.empty()){
13        auto [c,x,y] = pq.top();pq.pop();
14        if(x == n-1 && y == m-1 && c >= 1) return 1;
15        if(c < best[x][y]) continue;
16        for(int k = 0 ; k < 4 ; k++){
17          int i = dx[k] + x;
18          int j = dy[k] + y;
19          if(i < 0 || j < 0 || i >= n || j >= m) continue;
20          int nc = c + (grid[i][j] ? -1 : 0);
21          if(nc > best[i][j]) {
22            best[i][j] = nc;
23            pq.push({nc,i,j});
24          }
25        }
26      }
27      return 0;
28    }
29};