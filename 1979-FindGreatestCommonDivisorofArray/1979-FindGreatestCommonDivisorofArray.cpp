// Last updated: 7/19/2026, 2:58:44 PM
1class Solution {
2#define all(s) s.begin(), s.end()
3
4public:
5    int findGCD(vector<int>& nums) {
6        int mn = *min_element(all(nums));
7        int mx = *max_element(all(nums));
8        return __gcd(mx , mn);
9    }
10};