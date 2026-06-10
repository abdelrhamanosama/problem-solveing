// Last updated: 6/10/2026, 11:49:09 AM
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long n = nums.size(), sum = 0 , dp = 0;
        for(int i = 0 ; i<  n;i++){
            sum += nums[i];
            dp += i*nums[i]; 
        }
        long long ans = dp;
        for(int  k= 1;  k < n; k++){
            dp = dp + sum - n*nums[n-k];
            ans = max(dp , ans);
        }
        return ans;
    }
};