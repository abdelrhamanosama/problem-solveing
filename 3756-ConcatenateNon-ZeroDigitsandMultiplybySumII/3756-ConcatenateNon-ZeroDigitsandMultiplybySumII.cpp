// Last updated: 7/13/2026, 12:35:59 PM
1const int MOD = 1e9 + 7;
2const int MAX_N = 100001;
3vector<long long> pow10(MAX_N, 0);
4// init runs only once for all test cases
5int init = []() {
6    pow10[0] = 1;
7    for (int i = 1; i < MAX_N; ++i) {
8        pow10[i] = (pow10[i - 1] * 10) % MOD;
9    }
10    return 0;
11}();
12class Solution {
13public:
14    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
15        int n = s.size(), m = queries.size();
16        vector<long long> sum1(n + 1, 0), sum2(n + 1, 0), cnt(n + 1, 0);
17        vector<int> res(m, 0);
18        for (int i = 0; i < n; i++) {
19            sum1[i + 1] = (sum1[i] + s[i] - '0') % MOD;
20            sum2[i + 1] =
21                (s[i] - '0') > 0 ? (sum2[i] * 10 + s[i] - '0')%MOD : sum2[i];
22            cnt[i + 1] = (s[i] - '0') > 0 ? cnt[i] + 1 : cnt[i];
23        }
24        for (int i = 0; i < m; i++) {
25            int l = queries[i][0];
26            int r = queries[i][1] + 1;
27            long long len = cnt[r] - cnt[l];
28            long long val1 = (sum2[r] - sum2[l] * pow10[len] % MOD + MOD) % MOD;
29            long long val2 = (sum1[r] - sum1[l]) % MOD;
30            // cout << sum2[r] << "\t" << sum2[l] << "\t" << len << "\t";
31            // cout << val1 << "\t" << val2 << "\n";
32            res[i] = ((val1 * val2) % MOD);
33        }
34        return res;
35    }
36};