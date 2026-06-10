// Last updated: 6/10/2026, 11:49:24 AM
import java.util.Arrays;
class Solution {
public void moveZeroes(int[] nums){
        boolean flag = false;
        while(!flag)
        {   
            flag = true;
            for(int i =0 ; i < nums.length - 1; i ++)
                if(nums[i] == 0 && nums[i + 1] != 0)
                    {
                        int temp = nums[i];
                        nums[i] = nums[i + 1];
                        nums[i + 1] = temp;
                        flag = false;
                    }
        }
    }   
}