// Last updated: 9/6/2026, 2:24:19 PM
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> v;
        for(int i = 0 ; i < n; i++){
            v.push_back(nums[i]);
            v.push_back(nums[i+n]);
        }
        return v;
    }
};