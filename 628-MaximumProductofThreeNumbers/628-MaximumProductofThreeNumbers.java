// Last updated: 7/26/2026, 2:57:46 PM
1class Solution {
2    public int maximumProduct(int[] nums) {
3        Arrays.sort(nums);
4        int up = nums[nums.length-1]*nums[nums.length-2]*nums[nums.length-3];
5        int down = nums[0]*nums[1]*nums[nums.length-1];
6        return((up >= down)? up : down);
7    }
8}