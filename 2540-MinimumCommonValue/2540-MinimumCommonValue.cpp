// Last updated: 9/6/2026, 2:18:04 PM
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
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        for(int i = 0 ; i < nums1.size(); i++){
            int t = nums1[i];
            if(binary_search(all(nums2) , t)) return t;
        }
        return -1;
    }
};
