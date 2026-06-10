// Last updated: 6/10/2026, 3:55:17 PM
1#define sz(s) (int)(s).size()
2
3class Solution {
4public:
5    
6    vector<int> leftRightDifference(vector<int>& nums) {
7      int n = sz(nums);
8      vector<int> left(n,0) , right(n,0) , ans(n);   
9      for(int i = 1 ; i  < n; i ++){
10        left[i] = left[i-1] + nums[i-1];
11      }
12      for(int i = n-2 ; i >= 0 ; i --){
13        right[i] = right[i+1] + nums[i+1];
14      }
15      for(int i = 0 ; i < n;  i ++) ans[i] = abs(left[i] - right[i]);
16      return ans;
17    }
18};