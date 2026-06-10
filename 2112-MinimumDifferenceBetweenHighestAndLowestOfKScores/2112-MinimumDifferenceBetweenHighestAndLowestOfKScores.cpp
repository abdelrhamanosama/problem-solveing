// Last updated: 6/10/2026, 11:44:02 AM
class Solution {
#define all(s) s.begin(),s.end()

public:
    int minimumDifference(vector<int>& nums, int k) {
        // if(nums.size() == 1) return 0;
        sort(all(nums));
        int mn = 1e9;
        mn = nums[k-1] - nums[0];
        for(int i = k-1 ; i< nums.size(); i++){
            mn = min(mn , nums[i] - nums[i-k+1]);
        }
        return mn;
    }
};