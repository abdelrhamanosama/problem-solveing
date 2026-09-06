// Last updated: 9/6/2026, 2:12:50 PM
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0 ; i < n; i++){
          int cnt = 0;
          for(int j = i; j < n; j++){
            if(nums[j] == target) cnt++;
            if(cnt*2 > j-i+1){
              ans++;
            }
          }
        }
        return ans;    
    }
};