// Last updated: 11/8/2026, 4:24:19 AM
1
2import java.util.*;
3
4class Solution {
5    public int[] countServers(int n, int[][] logs, int x, int[] queries) {
6        int L = logs.length;
7        int Q = queries.length;
8
9        // Sort logs by time
10        Arrays.sort(logs, (a, b) -> Integer.compare(a[1], b[1]));
11
12        // Store query time and original index
13        int[][] sortedQueries = new int[Q][2];
14
15        for (int i = 0; i < Q; i++) {
16            sortedQueries[i][0] = queries[i];
17            sortedQueries[i][1] = i;
18        }
19
20        Arrays.sort(sortedQueries,
21            (a, b) -> Integer.compare(a[0], b[0]));
22
23        int[] freq = new int[n + 1];
24        int[] ans = new int[Q];
25
26        int left = 0;
27        int right = 0;
28        int activeServers = 0;
29
30        for (int[] query : sortedQueries) {
31            int q = query[0];
32            int idx = query[1];
33
34            int start = q - x;
35
36            // Add logs with time <= q
37            while (right < L && logs[right][1] <= q) {
38                int id = logs[right][0];
39
40                if (freq[id] == 0)
41                    activeServers++;
42
43                freq[id]++;
44                right++;
45            }
46
47            // Remove logs with time < q - x
48            while (left < right && logs[left][1] < start) {
49                int id = logs[left][0];
50
51                freq[id]--;
52
53                if (freq[id] == 0)
54                    activeServers--;
55
56                left++;
57            }
58
59            ans[idx] = n - activeServers;
60        }
61
62        return ans;
63    }
64}
65