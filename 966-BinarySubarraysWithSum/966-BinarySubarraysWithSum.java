// Last updated: 6/10/2026, 11:47:34 AM
class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            int sum  = 0;
            for (int j = i; j < nums.length; j++) {
                sum +=nums[j];
                if(sum == goal){
                    count++;
                }

            }
        }
        return  count;
    }
}