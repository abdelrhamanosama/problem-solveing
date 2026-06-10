// Last updated: 6/10/2026, 11:50:37 AM
class Solution {
public int removeDuplicates(int[] nums) {
        if (nums.length <= 2) return nums.length;
        
        int i = 0 , j = 0;
        for(;i < nums.length; i++){
            if(j < 2 || nums[i] != nums[j-2]) nums[j++] = nums[i];
        }
    return j;
    }
}