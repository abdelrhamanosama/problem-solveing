// Last updated: 6/25/2026, 1:26:35 AM
1constexpr int MOD = 1'000'000'007;
2
3class Solution {
4public:
5    int zigZagArrays(int n, int l, int r) {
6        int m = r - l + 1;
7        vector<int> dp0(m, 0);
8        vector<int> dp1(m, 0);
9        vector<int> sum0(m + 1, 0);
10        vector<int> sum1(m + 1, 0);
11
12        for (int i = 0; i < m; i++) {
13            dp0[i] = dp1[i] = 1;
14        }
15
16        for (int i = 1; i < n; i++) {
17            for (int j = 0; j < m; j++) {
18                sum0[j + 1] = (sum0[j] + dp0[j]) % MOD;
19                sum1[j + 1] = (sum1[j] + dp1[j]) % MOD;
20            }
21
22            for (int j = 0; j < m; j++) {
23                dp0[j] = (sum1[m] - sum1[j + 1] + MOD) % MOD;
24                dp1[j] = sum0[j];
25            }
26        }
27
28        auto op = [](int acc, int x) { return (acc + x) % MOD; };
29        auto ans0 = std::reduce(dp0.begin(), dp0.end(), 0, op);
30        auto ans1 = std::reduce(dp1.begin(), dp1.end(), 0, op);
31
32        return (ans0 + ans1) % MOD;
33    }
34};