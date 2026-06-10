// Last updated: 6/10/2026, 11:49:41 AM
import java.util.Arrays;

class Solution {
    public boolean containsDuplicate(int[] nums) {
        Arrays.sort(nums);
        boolean flag = false;
        for ( int i = 0 ; i < nums.length - 1; i ++)
            if(nums[i] == nums[i + 1])
            {
                flag = true;
                break;
            }
        return flag;        
    }
}