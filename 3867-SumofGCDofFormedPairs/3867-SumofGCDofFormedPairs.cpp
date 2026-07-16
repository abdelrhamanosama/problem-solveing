// Last updated: 7/16/2026, 2:14:27 PM
1class Solution {
2public:
3    long long gcdSum(vector<int>& nums) {
4        int mx = 0;
5        vector<int> v;
6        for(auto x:nums){
7            mx = max(mx , x);
8            v.push_back(__gcd(mx , x));
9        }
10        sort(v.begin() , v.end());
11        int l = 0 , r = nums.size()-1;
12        long long sum = 0;
13        while(l < r){
14            sum += __gcd(v[l] , v[r]);
15            l++;
16            r--;
17        }
18        return sum;
19    }
20};