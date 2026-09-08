// Last updated: 9/8/2026, 7:48:29 PM
1class Solution {
2    int bfs(int x, int y, int endx, int endy,
3            int n, int m, vector<vector<int>>& forest) {
4
5        queue<array<int, 3>> q;
6
7        int dx[] = {1, -1, 0, 0};
8        int dy[] = {0, 0, 1, -1};
9
10        vector<vector<int>> v(n, vector<int>(m, 1e9));
11
12        q.push({x, y, 0});
13        v[x][y] = 0;
14
15        while (!q.empty()) {
16            auto [i, j, cost] = q.front();
17            q.pop();
18
19            if (i == endx && j == endy)
20                return cost;
21
22            for (int k = 0; k < 4; k++) {
23                int nx = i + dx[k];
24                int ny = j + dy[k];
25
26                if (nx < 0 || ny < 0 ||
27                    nx >= n || ny >= m ||
28                    forest[nx][ny] == 0)
29                    continue;
30
31                int ncost = cost + 1;
32
33                if (ncost < v[nx][ny]) {
34                    v[nx][ny] = ncost;
35                    q.push({nx, ny, ncost});
36                }
37            }
38        }
39
40        return -1;
41    }
42
43public:
44    int cutOffTree(vector<vector<int>>& forest) {
45
46        int n = forest.size();
47        int m = forest[0].size();
48
49        vector<array<int, 3>> values;
50
51        for (int i = 0; i < n; i++) {
52            for (int j = 0; j < m; j++) {
53
54                if (forest[i][j] > 1) {
55                    values.push_back({
56                        forest[i][j],
57                        i,
58                        j
59                    });
60                }
61            }
62        }
63
64        sort(values.begin(), values.end());
65
66        int sx = 0;
67        int sy = 0;
68
69        long long res = 0;
70
71        for (auto [height, x, y] : values) {
72
73            int ans = bfs(
74                sx, sy,
75                x, y,
76                n, m,
77                forest
78            );
79
80            if (ans == -1)
81                return -1;
82
83            res += ans;
84
85            sx = x;
86            sy = y;
87        }
88
89        return res;
90    }
91};