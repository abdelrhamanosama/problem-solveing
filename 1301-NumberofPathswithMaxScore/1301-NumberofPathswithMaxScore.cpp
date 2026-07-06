// Last updated: 7/6/2026, 6:06:10 AM
1class Solution {
2public:
3     vector<int> pathsWithMaxScore(vector<string>& board) {
4    int dx[] = {-1,-1,0};
5    int dy[] = {-1,0,-1};
6    int n = board.size() , m = board[0].size() , mx = 0 , mod = 1e9 + 7;
7    queue<array<int, 3>> q;
8    vector<vector<int>> best(n,vector<int>(m,0)) ,ways(n, vector<int>(m,0));
9    q.push({n-1,m-1,0});
10    
11    ways[n-1][m-1] = 1;
12    while(!q.empty()){
13      auto [x,y,c] = q.front(); 
14      q.pop();
15        if(board[x][y] == 'E') {
16
17         continue;
18        }
19
20      for(int k = 0 ; k < 3 ; k++){
21        int i = dx[k] + x;
22        int j = dy[k] + y;
23        if(i < 0 || j < 0 || i >= n || j >= m) continue;
24        if(board[i][j] == 'X') continue;
25        char cost = board[i][j];
26        if(board[i][j] == 'E') cost = '0';
27        int nc = c + cost-'0';
28        if(best[i][j] == nc) {
29            ways[i][j] = (ways[x][y] + ways[i][j])%mod;
30        }
31        if(best[i][j] >= nc)  continue;
32          ways[i][j] = (ways[x][y] );
33          best[i][j] = nc;
34          q.push({i,j,nc});
35         
36      }
37      
38    }
39    vector<int> ans  = { best[0][0] , ways[0][0]};
40    return ans;
41  }
42};