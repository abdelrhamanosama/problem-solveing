// Last updated: 6/10/2026, 11:44:17 AM
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> v;
        for(auto &x: nums) v.push_back(x); 
        for(auto &x: nums) v.push_back(x); 
        return v;
    }
};