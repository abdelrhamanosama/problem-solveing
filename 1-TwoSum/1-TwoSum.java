// Last updated: 6/10/2026, 11:51:31 AM
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int [] out = new int [2];
        boolean flag = false;
        for(int i = 0 ; i < nums.length ; i++)
            if(!flag)
            for(int j = i + 1 ; j < nums.length ; j++)
                    if(nums[i] + nums[j] <= Integer.MAX_VALUE )
                            if(nums[i] + nums[j] == target)
                                {
                                    out[0] = i;
                                    out[1] = j;
                                    flag = true;
                                    break;
                                }
        return (out);
    }
}