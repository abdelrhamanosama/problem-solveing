// Last updated: 6/10/2026, 11:41:52 AM
class Solution {
public:
    int minElement(vector<int>& nums) {
        int mn = 1e9;
        for(auto x : nums){
            int y = x;
            int sum = 0;
            while(y){
                sum  +=  y%10;
                y/=10;
            }
            mn = min(mn , sum);
        }
        return mn;
    }
};