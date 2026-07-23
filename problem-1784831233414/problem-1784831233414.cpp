// Last updated: 7/23/2026, 9:27:13 PM
1class Solution {
2public:
3    int uniqueXorTriplets(vector<int>& nums) {
4        int n = nums.size();
5        if(n < 3) return n;
6        int cnt = 0;
7        while(n){
8            cnt++;
9            n=n>>1;
10        }
11        return 1<<cnt;
12    }
13};