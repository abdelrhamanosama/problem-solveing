// Last updated: 9/1/2026, 11:04:45 PM
1class Solution {
2public:
3
4    int n, m;
5    int fullMask;
6    int maxEnergy;
7
8    int id[20][20];
9
10    int dx[4] = {1, -1, 0, 0};
11    int dy[4] = {0, 0, 1, -1};
12
13    struct State {
14        int x, y;
15        int mask;
16        int energy;
17    };
18
19    int minMoves(vector<string>& classroom, int energy) {
20
21        n = classroom.size();
22        m = classroom[0].size();
23        maxEnergy = energy;
24
25        memset(id, -1, sizeof(id));
26
27        int cnt = 0;
28        int sx = 0, sy = 0;
29
30        for (int i = 0; i < n; i++) {
31            for (int j = 0; j < m; j++) {
32
33                if (classroom[i][j] == 'L') {
34                    id[i][j] = cnt++;
35                }
36
37                if (classroom[i][j] == 'S') {
38                    sx = i;
39                    sy = j;
40                }
41            }
42        }
43
44        fullMask = (1 << cnt) - 1;
45
46        int masks = 1 << cnt;
47
48        // visited[x][y][mask][energy]
49        int totalStates = n * m * masks * (energy + 1);
50
51        vector<bool> visited(totalStates, false);
52
53        auto getId = [&](int x, int y, int mask, int e) {
54            return (((x * m + y) * masks + mask) * (energy + 1) + e);
55        };
56
57        queue<State> q;
58
59        visited[getId(sx, sy, 0, energy)] = true;
60
61        q.push({sx, sy, 0, energy});
62
63        int moves = 0;
64
65        while (!q.empty()) {
66
67            int sz = q.size();
68
69            while (sz--) {
70
71                State cur = q.front();
72                q.pop();
73
74                int x = cur.x;
75                int y = cur.y;
76                int mask = cur.mask;
77                int e = cur.energy;
78
79                if (mask == fullMask) {
80                    return moves;
81                }
82
83                if (e == 0) {
84                    continue;
85                }
86
87                for (int d = 0; d < 4; d++) {
88
89                    int nx = x + dx[d];
90                    int ny = y + dy[d];
91
92                    if (nx < 0 || nx >= n ||
93                        ny < 0 || ny >= m) {
94                        continue;
95                    }
96
97                    if (classroom[nx][ny] == 'X') {
98                        continue;
99                    }
100
101                    int ne = e - 1;
102                    int nmask = mask;
103
104                    // Clean trash
105                    if (classroom[nx][ny] == 'L') {
106                        nmask |= (1 << id[nx][ny]);
107                    }
108
109                    // Recharge
110                    if (classroom[nx][ny] == 'R') {
111                        ne = maxEnergy;
112                    }
113
114                    int stateId = getId(nx, ny, nmask, ne);
115
116                    if (visited[stateId]) {
117                        continue;
118                    }
119
120                    visited[stateId] = true;
121
122                    q.push({
123                        nx,
124                        ny,
125                        nmask,
126                        ne
127                    });
128                }
129            }
130
131            moves++;
132        }
133
134        return -1;
135    }
136};