// Last updated: 6/10/2026, 11:44:26 AM
class Solution {
#define all(s) s.begin(),s.end()

public:
    int minPairSum(vector<int>& nums) {
        sort(all(nums));   
    int mx = 0, l = 0 , r = nums.size() -1;
    while(l < r){
        mx = max(mx , nums[l] + nums[r]);
        l++;
        r--;
    }
    return mx;
    
}
};