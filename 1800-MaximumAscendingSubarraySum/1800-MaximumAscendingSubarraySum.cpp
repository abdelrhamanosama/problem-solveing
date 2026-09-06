// Last updated: 9/6/2026, 2:21:27 PM
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0] , mx = 0;
        for(int i = 0; i < nums.size() -1; i++)       {
            if(nums[i] < nums[i+1])
                sum+= nums[i+1];
            else {
                mx = max(mx,sum);
                sum = nums[i+1];
            }
        }
        mx = max(mx,sum);
        return mx;
    }
};