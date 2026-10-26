// Last updated: 10/26/2026, 3:45:47 AM
1
2import java.util.ArrayList;
3import java.util.List;
4
5class Solution {
6    public int closedIsland(int[][] grid) {
7        int n = grid.length;
8        int m = grid[0].length;
9
10        DSU d = new DSU(n * m);
11
12        int[] dr = {-1, 1, 0, 0};
13        int[] dc = {0, 0, -1, 1};
14
15        // Merge adjacent land cells.
16        for (int i = 0; i < n; i++) {
17            for (int j = 0; j < m; j++) {
18                if (grid[i][j] != 0) continue;
19
20                int id = i * m + j;
21
22                for (int k = 0; k < 4; k++) {
23                    int ni = i + dr[k];
24                    int nj = j + dc[k];
25
26                    if (ni < 0 || ni >= n ||
27                        nj < 0 || nj >= m) {
28                        continue;
29                    }
30
31                    if (grid[ni][nj] == 0) {
32                        int nid = ni * m + nj;
33                        d.merge(id, nid);
34                    }
35                }
36            }
37        }
38
39        // Mark components that touch the border.
40        boolean[] touchesBorder = new boolean[n * m];
41
42        for (int i = 0; i < n; i++) {
43            for (int j = 0; j < m; j++) {
44                if (grid[i][j] != 0) continue;
45
46                if (i == 0 || i == n - 1 ||
47                    j == 0 || j == m - 1) {
48                    int root = d.find(i * m + j);
49                    touchesBorder[root] = true;
50                }
51            }
52        }
53
54        // Count distinct components that do not touch the border.
55        int ans = 0;
56
57        for (int i = 0; i < n * m; i++) {
58            if (grid[i / m][i % m] != 0) continue;
59
60            if (d.find(i) == i && !touchesBorder[i]) {
61                ans++;
62            }
63        }
64
65        return ans;
66    }
67
68    class DSU {
69        List<Integer> parents = new ArrayList<>();
70        List<Integer> cnt = new ArrayList<>();
71
72        DSU(int n) {
73            for (int i = 0; i < n; i++) {
74                parents.add(i);
75                cnt.add(1);
76            }
77        }
78
79        int find(int u) {
80            if (u == parents.get(u)) return u;
81
82            parents.set(u, find(parents.get(u)));
83            return parents.get(u);
84        }
85
86        void merge(int u, int v) {
87            int rootU = find(u);
88            int rootV = find(v);
89
90            if (rootU == rootV) return;
91
92            if (cnt.get(rootU) < cnt.get(rootV)) {
93                int temp = rootU;
94                rootU = rootV;
95                rootV = temp;
96            }
97
98            parents.set(rootV, rootU);
99            cnt.set(rootU, cnt.get(rootU) + cnt.get(rootV));
100        }
101    }
102}