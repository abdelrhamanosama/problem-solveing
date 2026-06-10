// Last updated: 6/10/2026, 11:42:21 AM
/* صلِّ على النبي */
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define sz(s) (int)(s).size()
#define all(s) s.begin(), s.end()

class Solution {
private:
    // اللهم اهدنا يا رب اليك
public:
    bool isGood(vector<int>& nums) {
        int mx = *max_element(all(nums));
        map<int, int> mp;
        for (auto x : nums) {
            ++mp[x];
            if (mp[x] == 1)
                continue;
            if (mp[x] == 2 && x == mx)
                continue;
            return 0;
        }
        if (mp[mx] == 2 && mp.size() == mx)

            return 1;
        else
            return 0;
    }
};
