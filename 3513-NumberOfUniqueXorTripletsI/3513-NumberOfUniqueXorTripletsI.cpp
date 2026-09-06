// Last updated: 9/6/2026, 2:14:29 PM
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return n;
        int cnt = 0;
        while(n){
            cnt++;
            n=n>>1;
        }
        return 1<<cnt;
    }
};