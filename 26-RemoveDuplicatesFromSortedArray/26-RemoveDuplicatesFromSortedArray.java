// Last updated: 6/10/2026, 11:51:06 AM
class Solution {
    public int removeDuplicates(int[] nums) {
        int []res = new int[nums.length];
        res[0] = 0 ;
        int j = nums[0] , temp = 1 , i ;
        for( i = 1 ; i  < nums.length ; i ++)
            {
                if(j!= nums[i])
                   {
                    res[temp++] = i;
                    j = nums[i];
                   }
            }
        i = 0;
        while( i < nums.length && res[i] < nums.length)
            {
                nums[i] = nums[res[i]];
                i++;
            }
        return (temp);
    }
}