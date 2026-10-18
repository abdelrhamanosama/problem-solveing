// Last updated: 10/18/2026, 6:20:25 PM
1class Solution {
2public:
3    int numOfWays(vector<int>& nums) {
4        const int MOD = 1e9 + 7;
5        int n = nums.size();
6        vector<long long> fact(n + 1, 1), inv(n + 1, 1);
7        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
8        inv[n] = modPow(fact[n], MOD - 2, MOD);
9        for (int i = n - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
10        auto comb = [&](int a, int b) -> long long {
11            if (b < 0 || b > a) return 0;
12            return fact[a] * inv[b] % MOD * inv[a - b] % MOD;
13        };
14        function<long long(vector<int>&)> ways = [&](vector<int>& arr) -> long long {
15            int m = arr.size();
16            if (m <= 1) return 1;
17            vector<int> left, right;
18            for (int x : arr) {
19                if (x < arr[0]) left.push_back(x);
20                else if (x > arr[0]) right.push_back(x);
21            }
22            return comb(m - 1, right.size()) * ways(left) % MOD * ways(right) % MOD;
23        };
24        return (ways(nums) - 1 + MOD) % MOD;
25    }
26private:
27    long long modPow(long long base, long long exp, long long mod) {
28        long long res = 1;
29        while (exp) {
30            if (exp & 1) res = res * base % mod;
31            base = base * base % mod;
32            exp >>= 1;
33        }
34        return res;
35    }
36};