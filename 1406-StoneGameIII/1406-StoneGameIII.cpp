// Last updated: 8/3/2026, 4:12:34 PM
1class Solution {
2    int n;
3    vector<int> stone;
4    int memo[50005][2];
5
6    int dp(int i, bool bobTurn) {
7        if (i >= n)
8            return 0;
9
10        int &ret = memo[i][bobTurn];
11        if (ret != INT_MIN)
12            return ret;
13
14        ret = bobTurn ? INT_MAX : INT_MIN;
15
16        int sum = 0;
17        for (int take = 1; take <= 3 && i + take - 1 < n; take++) {
18            sum += stone[i + take - 1];
19
20            int cur = dp(i + take, !bobTurn);
21
22            if (bobTurn)
23                ret = min(ret, cur - sum);
24            else
25                ret = max(ret, cur + sum);
26        }
27
28        return ret;
29    }
30
31public:
32    string stoneGameIII(vector<int>& stoneValue) {
33        stone = stoneValue;
34        n = stone.size();
35
36        for (int i = 0; i <= n; i++)
37            memo[i][0] = memo[i][1] = INT_MIN;
38
39        int diff = dp(0, false);
40
41        if (diff > 0) return "Alice";
42        if (diff < 0) return "Bob";
43        return "Tie";
44    }
45};