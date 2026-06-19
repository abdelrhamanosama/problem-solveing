// Last updated: 6/19/2026, 5:16:41 AM
1class Solution {
2public:
3    int largestAltitude(vector<int>& gain) {
4        int sum = 0 , mx = 0;
5        for(int i  : gain) 
6        {
7            sum += i;
8            mx = max(mx , sum);
9        }  
10        return mx;
11    }
12};