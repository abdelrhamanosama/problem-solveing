// Last updated: 9/6/2026, 4:02:51 PM
/* صلِّ على النبي */
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define sz(s) (int)(s).size()
#define all(s) s.begin(), s.end()

class Solution {

private:
    vector<int> v;
    int mem[22][22][2];
    int dp(int l, int r, int typ) {
        if (l > r)
            return 0;
        int& ret = mem[l][r][typ];
        if (~ret)
            return ret;
        // ret = -1e9;
        int opt1 = 0;
        int opt2 = 0;
        opt1 = dp(l, r - 1, typ ^ 1) + (typ ? -v[r] : v[r]);
        opt2 = dp(l + 1, r, typ ^ 1) + (typ ? -v[l] : v[l]);
        if (typ == 0)
            ret = max(opt1, opt2);
        else
            ret = min(opt1, opt2);
        return ret;
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        v = nums;
        memset(mem, -1, sizeof mem);
        return dp(0, nums.size() - 1, 0) >= 0;
    }
};