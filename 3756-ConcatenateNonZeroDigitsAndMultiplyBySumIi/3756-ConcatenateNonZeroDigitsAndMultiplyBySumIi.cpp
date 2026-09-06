// Last updated: 9/6/2026, 2:12:24 PM
const int MOD = 1e9 + 7;
const int MAX_N = 100001;
vector<long long> pow10(MAX_N, 0);
// init runs only once for all test cases
int init = []() {
    pow10[0] = 1;
    for (int i = 1; i < MAX_N; ++i) {
        pow10[i] = (pow10[i - 1] * 10) % MOD;
    }
    return 0;
}();
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size(), m = queries.size();
        vector<long long> sum1(n + 1, 0), sum2(n + 1, 0), cnt(n + 1, 0);
        vector<int> res(m, 0);
        for (int i = 0; i < n; i++) {
            sum1[i + 1] = (sum1[i] + s[i] - '0') % MOD;
            sum2[i + 1] =
                (s[i] - '0') > 0 ? (sum2[i] * 10 + s[i] - '0')%MOD : sum2[i];
            cnt[i + 1] = (s[i] - '0') > 0 ? cnt[i] + 1 : cnt[i];
        }
        for (int i = 0; i < m; i++) {
            int l = queries[i][0];
            int r = queries[i][1] + 1;
            long long len = cnt[r] - cnt[l];
            long long val1 = (sum2[r] - sum2[l] * pow10[len] % MOD + MOD) % MOD;
            long long val2 = (sum1[r] - sum1[l]) % MOD;
            // cout << sum2[r] << "\t" << sum2[l] << "\t" << len << "\t";
            // cout << val1 << "\t" << val2 << "\n";
            res[i] = ((val1 * val2) % MOD);
        }
        return res;
    }
};