// Last updated: 8/2/2026, 3:37:47 AM
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
14    vector<int> v;
15    int mem[501][501][2];
16    int dp(int l, int r, int typ) {
17        if (l > r)
18            return 0;
19        int& ret = mem[l][r][typ];
20        if (~ret)
21            return ret;
22        // ret = -1e9;
23        int opt1 = 0;
24        int opt2 = 0;
25        opt1 = dp(l, r - 1, typ ^ 1) + (typ ? -v[r] : v[r]);
26        opt2 = dp(l + 1, r, typ ^ 1) + (typ ? -v[l] : v[l]);
27        if (typ == 0)
28            ret = max(opt1, opt2);
29        else
30            ret = min(opt1, opt2);
31        return ret;
32    }
33
34public:
35    bool stoneGame(vector<int>& piles ) {
36        v = piles ;
37        memset(mem, -1, sizeof mem);
38        return dp(0, piles .size() - 1, 0) >= 0;
39    }
40};