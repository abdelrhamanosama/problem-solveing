// Last updated: 6/10/2026, 11:50:58 AM
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int , int> mp;
        int mx = 0;
        for(auto x:nums) {
            mp.insert({x,1});
            mx = max(mx , x);
        }
        for(int i = 1; i <=min(mx, int(1e5 + 2)); i++){
            if(mp.find(i) == mp.end()) return i;
        }
        return mx+1;
    }
};