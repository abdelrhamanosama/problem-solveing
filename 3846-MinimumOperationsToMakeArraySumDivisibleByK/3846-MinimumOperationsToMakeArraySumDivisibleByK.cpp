// Last updated: 6/10/2026, 11:41:34 AM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for(auto  x: nums) sum+=x;
        return sum%k;
    }
};