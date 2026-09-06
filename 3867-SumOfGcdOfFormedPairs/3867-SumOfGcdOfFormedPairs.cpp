// Last updated: 9/6/2026, 2:12:05 PM
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx = 0;
        vector<int> v;
        for(auto x:nums){
            mx = max(mx , x);
            v.push_back(__gcd(mx , x));
        }
        sort(v.begin() , v.end());
        int l = 0 , r = nums.size()-1;
        long long sum = 0;
        while(l < r){
            sum += __gcd(v[l] , v[r]);
            l++;
            r--;
        }
        return sum;
    }
};