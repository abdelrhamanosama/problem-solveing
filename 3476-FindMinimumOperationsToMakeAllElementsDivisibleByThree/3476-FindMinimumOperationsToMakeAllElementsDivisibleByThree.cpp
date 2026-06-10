// Last updated: 6/10/2026, 11:41:59 AM
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int sum = 0;
        for(auto x:nums){
            sum +=(x%3 == 0 ? 0 : 1 );
        }
        return sum;  
    }
};