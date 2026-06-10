// Last updated: 6/10/2026, 11:48:19 AM
class Solution {
  public double findMaxAverage(int[] nums, int k) {
      double avg = Long.MIN_VALUE ,temp = Double.MIN_VALUE;
      if(nums.length == k)
          {   avg = 0;
              for(int i : nums)
                  avg +=i;
                  return(avg/k);
          }
          int i = 0;
              /*method of prefix sum */
              for(i = 1; i <nums.length; i++) {
                nums[i] += nums[i-1];
            }
            
            for( i = k - 1; i < nums.length; i++) {
                if(avg < nums[i] && i == k - 1)
                    avg = nums[i];
                if(i -k >= 0)
                     if((avg < nums[i] - nums[i - k]) )
                        avg = nums[i] - nums[i - k];
            } 
            temp = avg / k;
          return temp;
  }
}
//[1,12,-5,-6,50,3]
/*
 * [1,13,8,2,52,55]
 */