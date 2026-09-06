// Last updated: 9/6/2026, 2:22:14 PM
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
        int minMoves(vector<int>& nums, int limit) {
            int n = nums.size();
            int ans = 1e9;
            vector<int> diff(2*limit+2,0);
            for(int i = 0 ; i < n/2; ++i ){
                int a = nums[i];
                int b = nums[n-i-1];
                int low = min(a,b)+1;
                int high = max(a,b) + limit;
                int sum = a+b;
                diff[2]+=2;
                diff[2*limit+1]-=2;
                diff[low]-=1;
                diff[high+1]+=1;
                diff[sum]-=1;
                diff[sum+1]+=1;
            }
            for(int i = 2; i <= 2*limit; i++)
                {
                    diff[i]+=diff[i-1];
                    ans = min(ans , diff[i]);       
                }
        return ans;
    }
};
