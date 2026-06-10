// Last updated: 6/10/2026, 11:48:25 AM
class Solution {
    public int maximumProduct(int[] nums) {
        Arrays.sort(nums);
        int up = nums[nums.length-1]*nums[nums.length-2]*nums[nums.length-3];
        int down = nums[0]*nums[1]*nums[nums.length-1];
        return((up >= down)? up : down);
    }
}