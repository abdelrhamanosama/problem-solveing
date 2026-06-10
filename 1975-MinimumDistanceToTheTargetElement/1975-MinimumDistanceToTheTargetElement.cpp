// Last updated: 6/10/2026, 11:44:29 AM
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = 1e9;
        for(int i = 0 ; i < nums.size(); i++){
            if(target == nums[i])
            ans = min(ans ,abs(i-start));
        }
        return ans;
    }
};