// Last updated: 6/10/2026, 11:50:22 AM
class Solution {
  public int singleNumber(int[] nums) {
    short [] ar1 = new short[30002];
    short [] ar2 = new short[30002]; //[4,1,2,1,2]
    for(int i = 0; i < nums.length; i++) {
        if(nums[i] >= 0)
          ar1[nums[i]]++;
        else
          ar2[nums[i]*-1]++;
      }
      for(int i = 0 ; i< 30002; i++) {
          if(ar1[i]%2 != 0)
            return i;
          if(ar2[i]%2 != 0)
            return i*-1; 
        }
        return 0;
  }
}