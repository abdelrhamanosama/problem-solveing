// Last updated: 9/6/2026, 3:57:24 PM
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for(auto x: nums){
            int y = x;
            int res = 0;
            while(y) {
                res++;
                y/=10;
            }
            cnt+=(res%2 == 0);
        }
        return cnt;
    }
};