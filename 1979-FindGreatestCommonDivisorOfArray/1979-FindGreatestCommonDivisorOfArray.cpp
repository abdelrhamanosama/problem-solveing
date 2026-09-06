// Last updated: 9/6/2026, 2:20:27 PM
class Solution {
#define all(s) s.begin(), s.end()

public:
    int findGCD(vector<int>& nums) {
        int mn = *min_element(all(nums));
        int mx = *max_element(all(nums));
        return __gcd(mx , mn);
    }
};