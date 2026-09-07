// Last updated: 9/7/2026, 6:15:28 PM
1class Solution {
2public:
3    int distinctSubseqII(string s) {
4        long long total = 0 , dp[26] = { },mod = 1e9+ 7;
5        for(auto x: s){
6            char c = x-'a';
7            int newEnd = (total + 1+mod)%mod;
8            total = (total- dp[c]+newEnd+mod)%mod;
9            dp[c] = newEnd%mod;
10        }
11        return total;
12    }
13};