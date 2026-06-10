// Last updated: 6/10/2026, 11:42:08 AM
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
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_set<string> s;
        for (int i = 0; i < arr1.size(); i++)
        {
            string st = to_string(arr1[i]), curr = "";
            for (auto x : st)
            {
                curr += x;
                s.insert(curr);
            }
        }
        int mx = 0;
        for (int i = 0; i < arr2.size(); i++)
        {
            string st = to_string(arr2[i]), curr = "";
            int j = 0;
            for (auto x : st)
            {
                curr += x;
                if(s.find(curr)!=s.end()) mx = max(mx , ++j);
            }
        }
        return mx;
    }
};
