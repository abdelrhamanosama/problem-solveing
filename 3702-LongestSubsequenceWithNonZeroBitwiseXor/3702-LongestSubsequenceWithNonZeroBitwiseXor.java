// Last updated: 9/6/2026, 2:12:52 PM
class Solution {
    public int longestSubsequence(int[] nums) {
        int t = 0;
        boolean zeros = true;
        for(int x:nums) {
            t^=x;
            if(x > 0) zeros = false;
        }
        if(t > 0) return nums.length;

        return zeros? 0 : nums.length-1;
    }
}