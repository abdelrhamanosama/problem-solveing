// Last updated: 10/26/2026, 3:58:39 AM
1class Solution {
2    public int countIslands(int[][] grid, int K) {
3        int n = grid.length;
4        int m = grid[0].length;
5
6        DSU d = new DSU(n * m);
7
8        int[] dr = { -1, 1, 0, 0 };
9        int[] dc = { 0, 0, -1, 1 };
10
11        // Merge adjacent land cells.
12        for (int i = 0; i < n; i++) {
13            for (int j = 0; j < m; j++) {
14                if (grid[i][j] == 0)
15                    continue;
16
17                int id = i * m + j;
18
19                for (int k = 0; k < 4; k++) {
20                    int ni = i + dr[k];
21                    int nj = j + dc[k];
22
23                    if (ni < 0 || ni >= n ||
24                            nj < 0 || nj >= m) {
25                        continue;
26                    }
27
28                    if (grid[ni][nj] != 0) {
29                        int nid = ni * m + nj;
30                        d.merge(id, nid);
31                    }
32                }
33            }
34        }
35
36        // Mark components that touch the border.
37        boolean[] touchesBorder = new boolean[n * m];
38
39        // for (int i = 0; i < n; i++) {
40        //     for (int j = 0; j < m; j++) {
41        //         if (grid[i][j] == 0) continue;
42
43        //         if (i == 0 || i == n - 1 ||
44        //             j == 0 || j == m - 1) {
45        //             int root = d.find(i * m + j);
46        //             touchesBorder[root] = true;
47        //         }
48        //     }
49        // }
50
51        // Count distinct components that do not touch the border.
52        int ans = 0;
53        long[] sum = new long[n * m];
54
55        for (int i = 0; i < n * m; i++) {
56            int r = i / m;
57            int c = i % m;
58
59            if (grid[r][c] == 0)
60                continue;
61
62            int root = d.find(i);
63            sum[root] += grid[r][c];
64        }
65
66        for (int i = 0; i < n * m; i++) {
67            if (d.find(i) == i && sum[i] > 0 && sum[i] % K == 0) {
68                ans++;
69            }
70        }
71
72        return ans;
73    }
74
75    class DSU {
76        List<Integer> parents = new ArrayList<>();
77        List<Integer> cnt = new ArrayList<>();
78
79        DSU(int n) {
80            for (int i = 0; i < n; i++) {
81                parents.add(i);
82                cnt.add(1);
83            }
84        }
85
86        int find(int u) {
87            if (u == parents.get(u))
88                return u;
89
90            parents.set(u, find(parents.get(u)));
91            return parents.get(u);
92        }
93
94        void merge(int u, int v) {
95            int rootU = find(u);
96            int rootV = find(v);
97
98            if (rootU == rootV)
99                return;
100
101            if (cnt.get(rootU) < cnt.get(rootV)) {
102                int temp = rootU;
103                rootU = rootV;
104                rootV = temp;
105            }
106
107            parents.set(rootV, rootU);
108            cnt.set(rootU, cnt.get(rootU) + cnt.get(rootV));
109        }
110    }
111}