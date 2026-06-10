// Last updated: 6/10/2026, 11:51:01 AM
class Solution {
    public int searchInsert(int[] nums, int target) {
       int r = 0 , l = nums.length - 1 , y = 0;
       while(l > r)
        {
            y = (r+ l)/2;
            if(nums[y] == target)
                    break;
            else  if(nums[y] > target)
                    l = y - 1;    
            else
                r = y + 1;
        }
        try{
        if (nums[y] == target ) ;
        
        else if(nums[r] >= target)
            y = r;
        else if(nums[r] < target)
            y = (r + 1);
        if(y == -1)
            y = 0;
        }
        catch(Exception e)
        {}
        finally{
            return y ;
        }           
    }
}