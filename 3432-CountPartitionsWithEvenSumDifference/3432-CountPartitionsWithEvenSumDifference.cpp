// Last updated: 9/6/2026, 2:14:59 PM
class Solution {
public:
    int countPartitions(vector<int>& nums) {
       int sum1 =0 ,sum2 = 0 , cnt = 0, n = nums.size();
       for(int i = 0 ; i < n; i++) sum2+= nums[i];
       for(int i = 0 ; i < n-1; i++){
            sum2-=nums[i];
            sum1 +=nums[i];
            if(!(abs(sum2-sum1)&1)) cnt++;
       }  
       return cnt;
    }
};