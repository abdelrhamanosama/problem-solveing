// Last updated: 6/10/2026, 11:48:53 AM
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx = 0;
        for(int i = 0 ; i < nums.size(); i++){
            int cnt = 0;
            if(nums[i] == 1) cnt++;
            while(i < nums.size() - 1 &&nums[i] == nums[i+1] && nums[i] == 1) {
                cnt++;
                i++;
            }
            mx = max(mx, cnt);
        }   
        return mx;
    }
};