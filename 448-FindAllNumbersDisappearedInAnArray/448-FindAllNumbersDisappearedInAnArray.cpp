// Last updated: 6/10/2026, 11:49:02 AM
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int> s;
        for(int i = 1 ; i <= nums.size(); i++) s.insert(i);
        for(auto x:nums) s.erase(x);
        vector<int> x;
        for(auto y:s) x.push_back(y);
        return x;
    }
};