// Last updated: 6/10/2026, 11:50:12 AM
class Solution {
    public int maxProduct(int[] nums) {
      int mx = (int)-1e9;
      int prodi= 1;
      int n = nums.length;
      for(int i = 0 ; i < n; i++){
        prodi *= nums[i];
        mx = Math.max(mx , prodi);
        if(nums[i] == 0) prodi = 1;
      }
      prodi = 1;
      for(int i = n-1 ; i>=0; i--){
        prodi *= nums[i];
        mx = Math.max(mx , prodi);
        if(nums[i] == 0) prodi = 1;
      }
        return mx;
    }
}