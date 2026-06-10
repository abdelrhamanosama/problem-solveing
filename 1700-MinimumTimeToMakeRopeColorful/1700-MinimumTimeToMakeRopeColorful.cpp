// Last updated: 6/10/2026, 11:45:32 AM
class Solution {
public:
    int minCost(string s, vector<int>& neededTime) {
       int n = s.size() ,ans = 0;
        for (int i = 0; i < n; i++) {
            int mx = neededTime[i];
            int sum = neededTime[i];
            while (i + 1 < n && s[i] == s[i + 1]) {
                mx = max(mx,neededTime[i+1]);
                sum += neededTime[i+1];
                i++;
            }
            // cout<<ans<<"\n";
            ans += (sum-mx);
        }
        // cout<<ans;
        return ans; 
    }
};