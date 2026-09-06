// Last updated: 9/6/2026, 2:17:38 PM
#define sz(s) (int)(s).size()

class Solution {
public:
    
    vector<int> leftRightDifference(vector<int>& nums) {
      int n = sz(nums);
      vector<int> left(n,0) , right(n,0) , ans(n);   
      for(int i = 1 ; i  < n; i ++){
        left[i] = left[i-1] + nums[i-1];
      }
      for(int i = n-2 ; i >= 0 ; i --){
        right[i] = right[i+1] + nums[i+1];
      }
      for(int i = 0 ; i < n;  i ++) ans[i] = abs(left[i] - right[i]);
      return ans;
    }
};