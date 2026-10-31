// Last updated: 10/31/2026, 4:11:35 AM
1class Solution {
2    int g[][];
3    int mem[][][];
4    int n,m;
5    int mod = (int)1e9+7;
6    int dp(int i , int j,int dir){
7        if(i >= n || j >= m ) return 0;
8        if(i == n-1 && j == m-1) return 1;
9        if(mem[i][j][dir] != -1)return mem[i][j][dir];
10        mem[i][j][dir] = 0;
11        int down , right;
12        down = right = 0;
13        // try go right
14        // 1 right
15        // 0 down
16        if(g[i][j] == 1){
17            if(dir == 1){
18                down = dp(i+1, j , 0);
19            }
20            else 
21                right = dp(i,j+1 , 1);
22        }
23        else 
24            {
25                down = dp(i+1, j , 0);
26                right = dp(i,j+1 , 1);
27            }
28        return mem[i][j][dir] = (right+down)%mod;
29    }
30    public int uniquePaths(int[][] grid) {
31        g = grid;
32        n = g.length;
33        m = g[0].length;
34        mem = new int[n+1][m+1][2];
35        for(int i = 0 ; i<n; i++)
36            for(int j = 0 ; j<m; j++)
37                Arrays.fill(mem[i][j] , -1);
38        return dp(0,0,0);
39    }
40}