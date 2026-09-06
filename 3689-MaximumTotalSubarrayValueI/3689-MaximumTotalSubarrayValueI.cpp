// Last updated: 9/6/2026, 2:12:57 PM
/* صلِّ على النبي */
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define sz(s) (int)(s).size()
#define all(s) s.begin(), s.end()

class Solution
{
private:
    // اللهم اهدنا يا رب اليك
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mx = *max_element(all(nums));
        long long mn = *min_element(all(nums));
        return k*(mx - mn);
    }
};
