// Last updated: 9/6/2026, 2:12:48 PM
class Solution {
public:
      long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> freq(2*n+1 , 0);
        freq[n] = 1;
        long long less = 0 , ans = 0 , curr = n; 
        for(auto x: nums){
          if(x == target){
            less += freq[curr++];
          }
          else {
            less-=freq[--curr];
          }
          freq[curr]++;
          ans +=less;
        }  
        return ans;
    }
};