// Last updated: 9/17/2026, 9:13:34 PM
1class Solution {
2public:
3    int minSumOfLengths(vector<int>& arr, int target) {
4
5        int n = arr.size();
6
7        vector<int> pref(n + 1, 0);
8
9        for (int i = 1; i <= n; i++)
10            pref[i] = pref[i - 1] + arr[i - 1];
11
12        const int INF = 1e9;
13
14        // best[i] = minimum length of a valid subarray
15        // starting at or after i
16        vector<int> best(n + 1, INF);
17
18        int ans = INF;
19
20        for (int i = n - 1; i >= 0; i--) {
21
22            // First inherit the best answer starting from i+1
23            best[i] = best[i + 1];
24
25            int l = i + 1;
26            int r = n;
27            int pos = -1;
28
29            while (l <= r) {
30
31                int mid = (l + r) >> 1;
32
33                int sum = pref[mid] - pref[i];
34
35                if (sum == target) {
36                    pos = mid;
37                    r = mid - 1;
38                }
39                else if (sum > target) {
40                    r = mid - 1;
41                }
42                else {
43                    l = mid + 1;
44                }
45            }
46
47            if (pos != -1) {
48
49                int len = pos - i;
50
51                // We need another subarray AFTER this one
52                if (best[pos] != INF)
53                    ans = min(ans, len + best[pos]);
54
55                // This is a candidate for future subarrays
56                best[i] = min(best[i], len);
57            }
58        }
59
60        return ans == INF ? -1 : ans;
61    }
62};