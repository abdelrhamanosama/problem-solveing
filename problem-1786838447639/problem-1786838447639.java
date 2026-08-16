// Last updated: 8/16/2026, 3:00:47 AM
1class Solution {
2    public int longestSubsequence(int[] nums) {
3        int t = 0;
4        boolean zeros = true;
5        for(int x:nums) {
6            t^=x;
7            if(x > 0) zeros = false;
8        }
9        if(t > 0) return nums.length;
10
11        return zeros? 0 : nums.length-1;
12    }
13}