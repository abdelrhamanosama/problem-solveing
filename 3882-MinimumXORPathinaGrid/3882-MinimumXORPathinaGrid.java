// Last updated: 10/29/2026, 2:48:34 AM
1class Solution {
2    int[][] grid;
3    Boolean[][][] memo;
4    int n, m;
5
6    boolean dp(int i, int j, int x) {
7        if (i >= n || j >= m)
8            return false;
9
10        int val = grid[i][j];
11        x ^= val;
12
13        if (i == n - 1 && j == m - 1)
14            return x == 0;
15
16        if (memo[i][j][x] != null)
17            return memo[i][j][x];
18
19        return memo[i][j][x] =
20            dp(i + 1, j, x) || dp(i, j + 1, x);
21    }
22
23    public int minCost(int[][] grid) {
24        this.grid = grid;
25        n = grid.length;
26        m = grid[0].length;
27
28        // XOR values are in [0, 1023].
29        memo = new Boolean[n][m][1024];
30
31        for (int target = 0; target < 1024; target++) {
32            if (dp(0, 0, target))
33                return target;
34        }
35
36        return -1;
37    }
38}