// Last updated: 7/14/2026, 5:54:52 AM
1class Solution {
2public:
3    long long mem[200][202][202];
4    int mod = 1e9 + 7;
5    long long dp(int i , int g1 , int g2 , int n ,vector<int> &nums){
6      if(i >= n) return g1==g2;
7      long long &ret = mem[i][g1][g2];
8      if(~ret) return ret;
9      ret = 0;
10      ret = (dp(i+1, __gcd(g1, nums[i]),g2,n,nums))%mod;
11      ret += (dp(i+1, g1,__gcd(g2,nums[i]),n,nums))%mod;
12      ret += (dp(i+1 ,g1,g2,n,nums))%mod;
13      ret %=mod;
14      return ret;
15    }
16    int subsequencePairCount(vector<int>& nums) {
17        memset(mem, -1 , sizeof mem);
18        return (int)dp(0,0,0,nums.size() , nums)-1;
19    }
20};