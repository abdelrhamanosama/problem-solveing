// Last updated: 9/6/2026, 2:22:39 PM
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long  sum = 0;
        for(int i = 0 ; i < nums.size(); i++){
            sum += nums[i];
        }
        if(sum%p == 0)return 0;
        int target = sum%p;
        map<long long,long long>mp;
        sum = 0;
        mp[0] =-1;
        long long mn = 1e9;
        for(int i = 0 ; i < nums.size(); i++){
            sum  = (sum + nums[i])%p;
            int needed = (sum - target + p)%p;
            if(mp.find(needed) != mp.end()){
                mn = min(mn , i-mp[needed]);
            }
            mp[sum] = i;
        }
        return (mn >= nums.size() ? -1 : mn);
    }

};