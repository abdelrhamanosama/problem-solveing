// Last updated: 9/6/2026, 2:21:03 PM
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