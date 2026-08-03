// Last updated: 8/3/2026, 6:49:45 PM
1class Solution {
2public:
3    int hIndex(vector<int>& citations) {
4        sort(citations.begin() , citations.end());
5        int n = citations.size() , ans = 0;
6        for(int i = n; i>=0; i--){
7            auto it = lower_bound(citations.begin() , citations.end() , i);
8            if(it == citations.end()) continue;
9            int diff = citations.end() - it;
10            if(i<=diff)
11                ans = max(ans  , i);
12        }
13        return ans;
14    }
15};