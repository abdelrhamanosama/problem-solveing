// Last updated: 7/26/2026, 9:25:27 PM
1class Solution {
2public:
3    int findNumbers(vector<int>& nums) {
4        int cnt = 0;
5        for(auto x: nums){
6            int y = x;
7            int res = 0;
8            while(y) {
9                res++;
10                y/=10;
11            }
12            cnt+=(res%2 == 0);
13        }
14        return cnt;
15    }
16};