// Last updated: 11/18/2026, 1:46:24 AM
1class Solution {
2
3    private int segmentCost(char[] s, int l, int m, List<Integer>[] factors) {
4        int best = m;
5        for (int d : factors[m]) {
6            int groups = m / d; // Each group contains groups characters
7            int changes = 0;
8            for (int offset = 0; offset < d; offset++) {
9                for (int t = 0; t < groups / 2; t++) {
10                    // Pair characters from opposite ends of the group
11                    if (
12                        s[l + offset + t * d] !=
13                        s[l + offset + (groups - 1 - t) * d]
14                    ) {
15                        changes++;
16                    }
17                }
18            }
19            best = Math.min(best, changes);
20        }
21        return best;
22    }
23
24    public int minimumChanges(String s, int k) {
25        int n = s.length();
26        char[] ch = s.toCharArray();
27        List<Integer>[] factors = new ArrayList[n + 1];
28        Arrays.setAll(factors, x -> new ArrayList<>());
29        // Precompute the proper divisors of each number
30        for (int d = 1; d <= n / 2; d++) {
31            for (int m = d * 2; m <= n; m += d) {
32                factors[m].add(d);
33            }
34        }
35        int[][] cost = new int[n][n];
36        for (int l = 0; l + 1 < n; l++) {
37            for (int r = l + 1; r < n; r++) {
38                // Each substring must have length at least 2
39                cost[l][r] = segmentCost(ch, l, r - l + 1, factors);
40            }
41        }
42        int[] prev = new int[n];
43        for (int start = 0; start < n; start++) {
44            // The case seg = 1
45            prev[start] = cost[start][n - 1];
46        }
47        for (int seg = 2; seg <= k; seg++) {
48            // Increase the number of segments from 2 to k
49            int[] cur = new int[n];
50            Arrays.fill(cur, n);
51            int limit = n - 1 - 2 * (seg - 1);
52            for (int start = 0; start + 2 * seg <= n; start++) {
53                // Leave at least 2*seg characters
54                for (int e = start + 1; e <= limit; e++) {
55                    cur[start] = Math.min(
56                        cur[start],
57                        cost[start][e] + prev[e + 1]
58                    );
59                }
60            }
61            prev = cur;
62        }
63        return prev[0];
64    }
65}