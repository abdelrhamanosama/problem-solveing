// Last updated: 11/8/2026, 4:10:42 AM
1class Solution {
2    public int countServers(int[][] grid) {
3        int n = grid.length;
4        int m = grid[0].length;
5
6        DSU d = new DSU(n * m);
7
8        for (int i = 0; i < n; i++) {
9            for (int j = 0; j < m; j++) {
10                if (grid[i][j] == 0)
11                    continue;
12
13                int id = i * m + j;
14
15                // Same column: up
16                for (int k = 0; k < i; k++) {
17                    if (grid[k][j] == 1)
18                        d.merge(id, k * m + j);
19                }
20
21                // Same column: down
22                for (int k = i + 1; k < n; k++) {
23                    if (grid[k][j] == 1)
24                        d.merge(id, k * m + j);
25                }
26
27                // Same row: left
28                for (int k = 0; k < j; k++) {
29                    if (grid[i][k] == 1)
30                        d.merge(id, i * m + k);
31                }
32
33                // Same row: right
34                for (int k = j + 1; k < m; k++) {
35                    if (grid[i][k] == 1)
36                        d.merge(id, i * m + k);
37                }
38            }
39        }
40
41        int ans = 0;
42
43        for (int i = 0; i < n * m; i++) {
44            if (grid[i / m][i % m] == 0)
45                continue;
46
47            if (d.find(i) == i && d.cnt.get(i) > 1) {
48                ans += d.cnt.get(i);
49            }
50        }
51
52        return ans;
53    }
54
55    class DSU {
56        List<Integer> parents = new ArrayList<>();
57        List<Integer> cnt = new ArrayList<>();
58
59        DSU(int n) {
60            for (int i = 0; i < n; i++) {
61                parents.add(i);
62                cnt.add(1);
63            }
64        }
65
66        int find(int u) {
67            if (u == parents.get(u))
68                return u;
69
70            parents.set(u, find(parents.get(u)));
71            return parents.get(u);
72        }
73
74        void merge(int u, int v) {
75            int rootU = find(u);
76            int rootV = find(v);
77
78            if (rootU == rootV)
79                return;
80
81            if (cnt.get(rootU) < cnt.get(rootV)) {
82                int temp = rootU;
83                rootU = rootV;
84                rootV = temp;
85            }
86
87            parents.set(rootV, rootU);
88            cnt.set(rootU, cnt.get(rootU) + cnt.get(rootV));
89        }
90    }
91}