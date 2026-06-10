// Last updated: 6/10/2026, 11:49:33 AM
class Solution {
    public int[] productExceptSelf(int[] nums) {
        long  max = 1;
        int count = 0;
        int arr[] = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            max *= nums[i];
            if(nums[i] == 0)
                count ++;
        }
        if(count == 0)
            for (int i = 0; i < nums.length; i++)
                arr[i] = (int)(max/nums[i]);
        else if(count > 1)
            for (int i = 0; i < nums.length; i++) {
                arr[i] = 0;
            }
        else {
            max = 1;
            for (int i = 0; i < nums.length; i++) {
                if(nums[i] != 0)
                    max *= nums[i];
            }
            for (int i = 0; i < nums.length; i++) {
                if(nums[i] != 0)
                    arr[i] = 0;
                else
                    arr[i] = (int)max;
            }
        }
        return arr;
    }
}