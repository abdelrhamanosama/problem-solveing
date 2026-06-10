// Last updated: 6/10/2026, 11:50:51 AM
/* صلِّ على النبي */
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define sz(s) (int)(s).size()
#define all(s) s.begin(), s.end()

class Solution
{
private:
    // اللهم اهدنا يا رب اليك
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size() , 0);
        set<pair<int,int>> s;
        dp[0] = 1;
        for(int i = 0 ; i < nums.size() ; i++){
            auto it = s.lower_bound({i,-1});
            if(it!=s.end()){
                dp[i] = dp[i]|dp[it->second];
            }
            s.insert({i+nums[i] , i});
        }
        return dp[nums.size()-1];
    }
};
