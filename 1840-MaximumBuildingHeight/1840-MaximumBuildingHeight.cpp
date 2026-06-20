// Last updated: 6/21/2026, 1:18:12 AM
1class Solution {
2public:
3    int maxBuilding(int num, vector<vector<int>>& r) {
4        r.push_back({1, 0});
5        sort(r.begin(), r.end());
6        int n = r.size();
7
8        for (int i = 1; i < n; i++)
9            r[i][1] = yCap(r[i - 1], r[i]);
10
11        for (int i = n - 2; i >= 0; i--)
12            r[i][1] = yCap(r[i + 1], r[i]);
13
14        int res = 0;
15        for (int i = 1; i < n; i++)
16            res = max(res, yPeak(r[i - 1], r[i]));
17
18        return max(res, r[n - 1][1] + num - r[n - 1][0]);
19    }
20
21    int yCap(vector<int>& l, vector<int>& r) {
22        int x1 = l[0], y1 = l[1], x2 = r[0], y2 = r[1];
23        return min(y2, y1 + abs(x2 - x1));
24    }
25
26    int yPeak(vector<int>& l, vector<int>& r) {
27        int x1 = l[0], y1 = l[1], x2 = r[0], y2 = r[1];
28        return (y1 + y2 + x2 - x1) >> 1;
29    }
30};