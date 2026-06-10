// Last updated: 6/10/2026, 11:41:14 AM
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<int> second_last(n+3,-1);
        vector<int> last(n+3,-1);
        int ans = 1<<30;
        for(int i = 0 ;i < n; i++){
            if(~second_last[nums[i]]) {
                ans = min(ans , (i-second_last[nums[i]])*2);
            }
            second_last[nums[i]] = last[nums[i]];
            last[nums[i]] = i;
        }
        return (ans==(1<<30) ? -1 : ans);
    }
};