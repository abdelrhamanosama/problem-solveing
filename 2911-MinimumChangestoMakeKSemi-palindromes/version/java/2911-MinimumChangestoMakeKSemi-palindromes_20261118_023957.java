// Last updated: 11/18/2026, 2:39:57 AM
1
2import java.util.Arrays;
3
4class Solution {
5    private static final int INF = 1_000_000_000;
6
7    int[][] cost;
8    int[][] mem;
9    int n, K;
10
11    // Calculate changes needed to make s[l...r-1]
12    // a semi-palindrome using divisor d.
13    private int count(String s, int l, int r, int d) {
14        int changes = 0;
15        int len = r - l;
16
17        for (int rem = 0; rem < d; rem++) {
18            int left = rem;
19            int right = len - d + rem;
20
21            while (left < right) {
22                if (s.charAt(l + left) != s.charAt(l + right))
23                    changes++;
24
25                left += d;
26                right -= d;
27            }
28        }
29
30        return changes;
31    }
32
33    // Precompute minimum cost of every substring.
34    private void buildCost(String s) {
35        cost = new int[n][n + 1];
36
37        for (int i = 0; i < n; i++)
38            Arrays.fill(cost[i], INF);
39
40        for (int l = 0; l < n; l++) {
41            for (int r = l + 2; r <= n; r++) {
42                int len = r - l;
43
44                for (int d = 1; d < len; d++) {
45                    if (len % d != 0)
46                        continue;
47
48                    cost[l][r] = Math.min(
49                        cost[l][r],
50                        count(s, l, r, d)
51                    );
52                }
53            }
54        }
55    }
56
57    // Minimum cost to divide s[i...n-1]
58    // into exactly k segments.
59    private int dp(int i, int k) {
60        if (k == 0)
61            return i == n ? 0 : INF;
62
63        // Not enough characters for k segments.
64        if (n - i < 2 * k)
65            return INF;
66
67        if (mem[i][k] != -1)
68            return mem[i][k];
69
70        int ans = INF;
71
72        // Choose the ending position of the current segment.
73        for (int j = i + 2; j <= n; j++) {
74            int next = dp(j, k - 1);
75
76            if (next == INF)
77                continue;
78
79            ans = Math.min(ans, cost[i][j] + next);
80        }
81
82        return mem[i][k] = ans;
83    }
84
85    public int minimumChanges(String s, int k) {
86        n = s.length();
87        K = k;
88
89        buildCost(s);
90
91        mem = new int[n + 1][K + 1];
92
93        for (int i = 0; i <= n; i++)
94            Arrays.fill(mem[i], -1);
95
96        return dp(0, K);
97    }
98}
99