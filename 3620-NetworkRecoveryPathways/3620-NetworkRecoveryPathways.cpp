// Last updated: 7/3/2026, 6:05:54 AM
1class Solution {
2public:
3    int maximumSafenessFactor(vector<vector<int>>& grid) {
4      int n = grid.size() , m = grid[0].size();
5      int dx [] = {1,-1,0,0};
6      int dy [] = {0,0,1,-1};
7      vector<vector<int>> dist(n ,vector<int> (m , 1e9));    
8      queue<array<int,2>> q;
9      for(int i = 0 ; i < n; i++) 
10        for(int j = 0 ; j < m; j++)
11          if(grid[i][j] == 1) {
12            q.push({i,j});
13            dist[i][j] = 0;
14          }
15      while(!q.empty()) {
16        auto [x,y] = q.front(); 
17        q.pop();
18        for(int k = 0 ; k < 4 ; k++){
19          int i = x+dx[k];
20          int j = y+dy[k];
21          if(i < 0 || j < 0 || i >= n || j >= m) continue;
22          if(dist[i][j] != 1e9) continue;
23          dist[i][j] = dist[x][y] + 1;
24          q.push({i,j});
25        }
26      }
27      priority_queue<array<int,3>>pq;
28      vector<vector<int>> best(n, vector<int>(n, -1));
29      pq.push({dist[0][0] , 0 ,0 });
30      best[0][0] = dist[0][0];
31      while(!pq.empty()){
32        auto [c,x,y] = pq.top();
33        pq.pop();
34        if(x == n-1 && y == m-1) return c;
35        if(c < best[x][y]) continue;
36        for(int k = 0 ; k <4 ; k++)
37          {
38            int i = x+dx[k];
39            int j = y+dy[k];
40            if(i < 0 || j < 0 || i >= n || j >= m) continue;
41            int nc = min(dist[i][j] , c);
42            if(nc > best[i][j])
43            {
44                best[i][j] = nc;
45                pq.push({nc,i,j});
46            }
47          }
48      }
49      return 0;
50    }
51};