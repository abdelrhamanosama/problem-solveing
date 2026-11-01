// Last updated: 11/1/2026, 9:20:35 AM
1class Solution {
2    public int minMoves(int[] nums) {
3        int mn = (int)1e9+7;
4        for(var x : nums) 
5            mn = Math.min(mn,x);
6        int ans = 0;
7        for(var x : nums) 
8            ans += x-mn;
9        return ans;
10    }
11}