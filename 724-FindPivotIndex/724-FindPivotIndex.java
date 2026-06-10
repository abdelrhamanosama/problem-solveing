// Last updated: 6/10/2026, 11:48:03 AM
class Solution {
    public int pivotIndex(int[] nums) {
        for(int i = 0; i < nums.length; i++)
            nums[i] = (i==0)? nums[i] : nums[i] + nums[i - 1];
        for (int i : nums) {
            System.out.print(i +"\t");
        }
        System.out.println();
        for(int i = 0; i < nums.length; i++) {
            int right = nums[nums.length - 1] - nums[i];
            int left = (i > 0)? nums[i-1]:0;
            if(left == right) {
                return i;
            }      
        }
        return -1;
    }
}