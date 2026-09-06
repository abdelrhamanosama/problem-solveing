// Last updated: 9/6/2026, 4:03:54 PM
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin() , citations.end());
        int n = citations.size() , ans = 0;
        for(int i = n; i>=0; i--){
            auto it = lower_bound(citations.begin() , citations.end() , i);
            if(it == citations.end()) continue;
            int diff = citations.end() - it;
            if(i<=diff)
                ans = max(ans  , i);
        }
        return ans;
    }
};