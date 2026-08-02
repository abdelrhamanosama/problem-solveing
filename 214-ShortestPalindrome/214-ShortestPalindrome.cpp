// Last updated: 8/2/2026, 3:20:11 AM
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
11class Solution
12{
13
14private:
15
16struct DoubleHash {
17
18    // using ll = long long;
19
20    static const int MOD1 = 1000000007;
21    static const int MOD2 = 1000000009;
22
23    static const int BASE1 = 911382323;
24    static const int BASE2 = 972663749;
25
26    vector<ll> h1, h2;
27    vector<ll> p1, p2;
28    int n;
29    DoubleHash(const string &s) {
30
31        n = s.size();
32
33        h1.assign(n + 1, 0);
34        h2.assign(n + 1, 0);
35
36        p1.assign(n + 1, 1);
37        p2.assign(n + 1, 1);
38
39        for (int i = 1; i <= n; i++) {
40
41            p1[i] = (p1[i - 1] * BASE1) % MOD1;
42            p2[i] = (p2[i - 1] * BASE2) % MOD2;
43
44            h1[i] = (h1[i - 1] * BASE1 + s[i - 1]) % MOD1;
45            h2[i] = (h2[i - 1] * BASE2 + s[i - 1]) % MOD2;
46        }
47    }
48
49    pair<ll,ll> get_hash(int l, int r) {
50
51        ll x1 = (h1[r + 1] -
52                 h1[l] * p1[r - l + 1]) % MOD1;
53
54        if (x1 < 0)
55            x1 += MOD1;
56
57        ll x2 = (h2[r + 1] -
58                 h2[l] * p2[r - l + 1]) % MOD2;
59
60        if (x2 < 0)
61            x2 += MOD2;
62
63        return {x1, x2};
64    }
65
66    bool equal(int l1,int r1,int l2,int r2){
67
68        return get_hash(l1,r1) == get_hash(l2,r2);
69    }
70
71};
72
73bool isPalindrome(int l,int r,DoubleHash &H,DoubleHash &RH){
74 
75    auto a = H.get_hash(l,r);
76 
77    int n = H.n;
78 
79    int rl = n-1-r;
80    int rr = n-1-l;
81 
82    auto b = RH.get_hash(rl,rr);
83 
84    return a==b;
85}
86public:
87    string longestPrefix(string s) {
88        DoubleHash h(s);
89        int ans = -1;
90        
91        for(int i = 0 , j = s.size() - 1 ; i < s.size()-1; i++,j--){
92            if(h.equal(0,i,j,s.size()-1)){
93                ans = i;
94            }
95        }
96        
97        return s.substr(0,ans+1);
98    }
99};