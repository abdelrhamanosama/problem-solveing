// Last updated: 9/6/2026, 2:20:59 PM
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int cnt = 0, y = 0 , i = 0;
        map<int,int> mp;
        for(auto x:nums) mp[x]++;
        for(auto it = mp.rbegin(); it != mp.rend() && i < mp.size() - 1; it++ , i++){
            cnt +=  (y + it->second);
            y += it->second;
        }
        return cnt;
    }
};