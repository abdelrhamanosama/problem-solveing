// Last updated: 8/2/2026, 2:53:26 AM
1/* صلِّ على النبي */
2#include <bits/stdc++.h>
3
4#include <ext/pb_ds/assoc_container.hpp>
5using namespace __gnu_pbds;
6using namespace std;
7#define ll long long
8#define sz(s) (int)(s).size()
9#define all(s) s.begin(), s.end()
10
11class Solution {
12
13private:
14    struct DoubleHash {
15
16        // using ll = long long;
17
18        static const int MOD1 = 1000000007;
19        static const int MOD2 = 1000000009;
20
21        static const int BASE1 = 911382323;
22        static const int BASE2 = 972663749;
23
24        vector<ll> h1, h2;
25        vector<ll> p1, p2;
26        int n;
27        DoubleHash(const string& s) {
28
29            n = s.size();
30
31            h1.assign(n + 1, 0);
32            h2.assign(n + 1, 0);
33
34            p1.assign(n + 1, 1);
35            p2.assign(n + 1, 1);
36
37            for (int i = 1; i <= n; i++) {
38
39                p1[i] = (p1[i - 1] * BASE1) % MOD1;
40                p2[i] = (p2[i - 1] * BASE2) % MOD2;
41
42                h1[i] = (h1[i - 1] * BASE1 + s[i - 1]) % MOD1;
43                h2[i] = (h2[i - 1] * BASE2 + s[i - 1]) % MOD2;
44            }
45        }
46
47        pair<ll, ll> get_hash(int l, int r) {
48
49            ll x1 = (h1[r + 1] - h1[l] * p1[r - l + 1]) % MOD1;
50
51            if (x1 < 0)
52                x1 += MOD1;
53
54            ll x2 = (h2[r + 1] - h2[l] * p2[r - l + 1]) % MOD2;
55
56            if (x2 < 0)
57                x2 += MOD2;
58
59            return {x1, x2};
60        }
61
62        bool equal(int l1, int r1, int l2, int r2) {
63
64            return get_hash(l1, r1) == get_hash(l2, r2);
65        }
66    };
67
68    bool isPalindrome(int l, int r, DoubleHash& H, DoubleHash& RH) {
69
70        auto a = H.get_hash(l, r);
71
72        int n = H.n;
73
74        int rl = n - 1 - r;
75        int rr = n - 1 - l;
76
77        auto b = RH.get_hash(rl, rr);
78
79        return a == b;
80    }
81
82public:
83    string shortestPalindrome(string s) {
84        string rev = s;
85        reverse(all(rev));
86        if (s.empty() || s == rev)
87            return s;
88
89        DoubleHash H(s), RH(rev);
90
91        int last = 0;
92
93        for (int i = s.size() - 1; i >= 0; i--) {
94            if (isPalindrome(0, i, H, RH)) {
95                last = i;
96                break;
97            }
98        }
99
100        string add = s.substr(last + 1);
101        reverse(add.begin(), add.end());
102
103        return add + s;
104    }
105};