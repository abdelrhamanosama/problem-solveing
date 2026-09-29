// Last updated: 9/29/2026, 11:13:05 AM
1class Solution {
2public:
3    int n, m;
4    vector<vector<char>> g;
5    int mem[100][100][205];
6
7    int dp(int i, int j, int cnt) {
8
9        if (i >= n || j >= m)
10            return 0;
11
12        if (cnt < 0)
13            return 0;
14
15        if (cnt > n + m)
16            return 0;
17
18        if (i == n - 1 && j == m - 1) {
19            if (g[i][j] == '(')
20                cnt++;
21            else
22                cnt--;
23
24            return cnt == 0;
25        }
26
27        int &ret = mem[i][j][cnt];
28
29        if (~ret)
30            return ret;
31
32        ret = 0;
33
34        if (g[i][j] == '(') {
35            cnt++;
36
37            ret = dp(i + 1, j, cnt);
38            ret = max(ret, dp(i, j + 1, cnt));
39        }
40        else {
41            if (cnt == 0)
42                return ret = 0;
43
44            cnt--;
45
46            ret = dp(i + 1, j, cnt);
47            ret = max(ret, dp(i, j + 1, cnt));
48        }
49
50        return ret;
51    }
52
53    bool hasValidPath(vector<vector<char>>& grid) {
54        n = grid.size();
55        m = grid[0].size();
56
57        g = grid;
58
59        memset(mem, -1, sizeof(mem));
60
61        // A valid parentheses string must have even length.
62        if ((n + m - 1) % 2)
63            return false;
64
65        return dp(0, 0, 0);
66    }
67};