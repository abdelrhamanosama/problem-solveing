// Last updated: 6/10/2026, 11:51:05 AM
import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    public int removeElement(int[] nums, int val) {
       byte k = 0 ; 
       for(byte i = 0 ; i < nums.length ; i ++)
            if(nums[i] != val )
                {
                    k++;
                }
            else
                nums[i] = 200;
        Arrays.sort(nums);
        return k ; 
    }
    
}