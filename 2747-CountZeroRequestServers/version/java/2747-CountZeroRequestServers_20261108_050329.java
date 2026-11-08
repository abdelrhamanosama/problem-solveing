// Last updated: 11/8/2026, 5:03:29 AM
1class Solution {
2    public int[] countServers(int n, int[][] logs, int x, int[] queries) {
3        int L = logs.length;
4        int q = queries.length;
5        Arrays.sort(logs, (a, b) -> Integer.compare(a[1], b[1]));
6        int[][] sortedQ = new int[q][2];
7        for (int i = 0; i < q; i++) {
8            sortedQ[i][0] = queries[i];
9            sortedQ[i][1] = i;
10        }
11        Arrays.sort(sortedQ, (a, b) -> Integer.compare(a[0], b[0]));
12        int left = 0, right = 0;
13        int freq[] = new int[n + 1];
14        int ans[] = new int[q];
15        int res = 0;
16        for (int i = 0; i < q; i++) {
17            int qq = sortedQ[i][0];
18            int id = sortedQ[i][1];
19            int start = qq - x;
20            
21            while (right < L && logs[right][1] <= qq) {
22                int idx = logs[right][0];
23
24                if (freq[idx] == 0)
25                    res++;
26
27                freq[idx]++;
28                right++;
29            }
30            while (left < right && logs[left][1] < start) {
31                int idx = logs[left][0];
32                freq[idx]--;
33                if (freq[idx] == 0)
34                    res--;
35                left++;
36            }
37            ans[id] = n - res;
38        }
39        return ans;
40    }
41}