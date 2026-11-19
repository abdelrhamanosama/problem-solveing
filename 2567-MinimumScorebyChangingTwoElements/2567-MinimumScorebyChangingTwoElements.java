// Last updated: 11/19/2026, 7:23:47 AM
1class Solution {
2    public int minimizeSum(int[] nums) {
3        int n = nums.length;
4        if(n == 3) return 0;
5        Arrays.sort(nums);
6        return Math.min(Math.min(nums[n - 1] - nums[2],
7                     nums[n - 3] - nums[0]),nums[n-2]-nums[1]);
8
9    }
10}
11
12// 1 4 5 7 8
13// 1 3 4
14// 1 2 3  6 7 8
15// 8 28 42 58 75