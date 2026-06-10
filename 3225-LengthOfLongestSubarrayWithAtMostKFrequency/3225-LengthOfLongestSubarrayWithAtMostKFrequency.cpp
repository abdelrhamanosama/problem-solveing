// Last updated: 6/10/2026, 11:42:11 AM
class Solution {
public:
Solution()
    {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); 
        cout.tie(NULL);
    }
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int , int> mp;
        int n = nums.size();
        int ans = 0, i, j;
        for ( i = 0, j = 0; i < n; i++)
        {
           mp[nums[i]]++;
                ans = max(ans , (i-j));
                while(mp[nums[i]] > k && j < i){
                    mp[nums[j]]--;j++;
                }
        }
                ans = max(ans , (i-j));
        return ans;
    }
};