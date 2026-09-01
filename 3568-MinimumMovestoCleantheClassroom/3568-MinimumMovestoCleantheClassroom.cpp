// Last updated: 9/1/2026, 10:58:07 PM
1class Solution {
2    static constexpr int dx[4] = {0, 1, 0, -1};
3    static constexpr int dy[4] = {1, 0, -1, 0};
4
5public:
6    int minMoves(vector<string>& classroom, int energy) {
7        int m = classroom.size();
8        int n = classroom[0].size();
9        vector id(m, vector<int>(n));
10        int sx, sy, cnt = 0;
11        for (int i = 0; i < m; i++) {
12            for (int j = 0; j < n; j++) {
13                if (classroom[i][j] == 'S') {
14                    sx = i;
15                    sy = j;
16                } else if (classroom[i][j] == 'L') {
17                    id[i][j] = 1 << cnt++;
18                }
19            }
20        }
21
22        vector bestEnergy(m, vector(n, vector<int>(1 << cnt, -1)));
23        bestEnergy[sx][sy][0] = energy;
24        struct Info {
25            int x, y, mask, e, steps;
26        };
27        queue<Info> q;
28        q.push({sx, sy, 0, energy, 0});
29        while (!q.empty()) {
30            Info t = q.front();
31            q.pop();
32            if (t.mask == (1 << cnt) - 1) {
33                return t.steps;
34            }
35            if (t.e == 0) {
36                continue;
37            }
38            for (int i = 0; i < 4; i++) {
39                int nx = t.x + dx[i];
40                int ny = t.y + dy[i];
41
42                if (nx < 0 || nx >= m || ny < 0 || ny >= n ||
43                    classroom[nx][ny] == 'X') {
44                    continue;
45                }
46
47                int ne = classroom[nx][ny] == 'R' ? energy : t.e - 1;
48                int nmask = t.mask | id[nx][ny];
49
50                if (ne > bestEnergy[nx][ny][nmask]) {
51                    bestEnergy[nx][ny][nmask] = ne;
52                    q.push({nx, ny, nmask, ne, t.steps + 1});
53                }
54            }
55        }
56        return -1;
57    }
58};