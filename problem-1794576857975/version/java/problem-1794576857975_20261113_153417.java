// Last updated: 11/13/2026, 3:34:17 PM
1
2import java.util.*;
3
4class Solution {
5    int N;
6    int[] c;
7    int[] mem;
8
9    int dp(int i) {
10        if (i == N)
11            return 0;
12
13        if (mem[i] != -1)
14            return mem[i];
15
16        int ans = Integer.MAX_VALUE;
17
18        for (int j = i + 1; j <= Math.min(i + 3, N); j++) {
19            int cost = c[j] + (j - i) * (j - i);
20            ans = Math.min(ans, dp(j) + cost);
21        }
22
23        return mem[i] = ans;
24    }
25
26    public int climbStairs(int n, int[] costs) {
27        N = n;
28
29        c = new int[n + 1];
30
31        for (int i = 0; i < n; i++)
32            c[i + 1] = costs[i];
33
34        mem = new int[n + 1];
35        Arrays.fill(mem, -1);
36
37        return dp(0);
38    }
39}
40