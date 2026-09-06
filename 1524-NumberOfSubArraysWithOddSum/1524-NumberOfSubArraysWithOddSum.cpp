// Last updated: 9/6/2026, 2:23:35 PM
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7;
        int even = 1 , odd = 0 , ans = 0 , sum = 0;
        for(auto x: arr){
            sum += x;
            if(sum&1){
                ans = (ans + even)%mod;
                odd++;
            }
            else {
                ans = (ans + odd)%mod;
                even++;
            }
        }
        return ans;
    }
};