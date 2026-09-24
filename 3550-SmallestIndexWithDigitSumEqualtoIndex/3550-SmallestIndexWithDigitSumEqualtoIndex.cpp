// Last updated: 9/23/2026, 8:36:29 PM
1class Solution {
2public:
3    int smallestIndex(vector<int>& nums) {
4        int mn = 200;
5        for(int i = 0 ; i <nums.size(); ++i){
6            int x = nums[i];
7            int sum = 0;
8            while(x){
9                sum+=x%10;
10                x/=10;
11            }
12            if(sum == i) return i;
13        }
14        return mn == 200 ? -1 : mn;
15    }
16};