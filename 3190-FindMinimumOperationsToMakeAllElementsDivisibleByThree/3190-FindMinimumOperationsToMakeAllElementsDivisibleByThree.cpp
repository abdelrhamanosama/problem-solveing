// Last updated: 9/6/2026, 2:15:49 PM
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