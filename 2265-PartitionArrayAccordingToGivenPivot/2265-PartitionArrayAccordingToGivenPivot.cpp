// Last updated: 6/10/2026, 11:43:00 AM
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
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> before , after;
        int cnt = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] < pivot)
                before.push_back(nums[i]);
            else if(nums[i] > pivot)
                after.push_back(nums[i]);

            else 
                cnt++;
        }
        vector<int> done;
        for(auto x: before)
            done.push_back(x);
        while(cnt--)
            done.push_back(pivot);
        for(auto x: after)
            done.push_back(x);
        return done;
    }
};
