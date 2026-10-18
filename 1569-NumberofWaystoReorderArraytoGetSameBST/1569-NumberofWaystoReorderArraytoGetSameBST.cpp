// Last updated: 10/18/2026, 6:36:02 PM
1
2class Solution {
3    int mod = 1e9 + 7;
4    int n = 1e3 + 5;
5    vector<long long> fact, inv;
6
7public:
8    int numOfWays(vector<int>& nums) {
9        fact.resize(n + 1, 1);
10        inv.resize(n + 1, 1);
11
12        for (int i = 1; i <= n; i++)
13            fact[i] = fact[i - 1] * i % mod;
14
15        inv[n] = modPow(fact[n], mod - 2, mod);
16
17        for (int i = n - 1; i >= 0; i--)
18            inv[i] = inv[i + 1] * (i + 1) % mod;
19
20        return (rec(nums) - 1 + mod) % mod;
21    }
22
23    int ncr(int a, int b) {
24        return fact[a] * inv[b] % mod * inv[a - b] % mod;
25    }
26
27    int rec(vector<int> arr) {
28        int m = arr.size();
29
30        if (m <= 2) return 1;
31
32        vector<int> left, right;
33
34        for (int i : arr) {
35            if (i > arr[0]) right.push_back(i);
36            else if (i < arr[0]) left.push_back(i);
37        }
38
39        return 1LL * ncr(m - 1, left.size())
40            * rec(left) % mod * rec(right) % mod;
41    }
42
43    long long modPow(long long base, long long exp, long long mod) {
44        long long res = 1;
45
46        while (exp) {
47            if (exp & 1) res = res * base % mod;
48            base = base * base % mod;
49            exp >>= 1;
50        }
51
52        return res;
53    }
54};
55