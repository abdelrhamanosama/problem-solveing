// Last updated: 9/6/2026, 2:15:19 PM
class Solution {
public:
    long long mem[200][202][202];
    int mod = 1e9 + 7;
    long long dp(int i , int g1 , int g2 , int n ,vector<int> &nums){
      if(i >= n) return g1==g2;
      long long &ret = mem[i][g1][g2];
      if(~ret) return ret;
      ret = 0;
      ret = (dp(i+1, __gcd(g1, nums[i]),g2,n,nums))%mod;
      ret += (dp(i+1, g1,__gcd(g2,nums[i]),n,nums))%mod;
      ret += (dp(i+1 ,g1,g2,n,nums))%mod;
      ret %=mod;
      return ret;
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(mem, -1 , sizeof mem);
        return (int)dp(0,0,0,nums.size() , nums)-1;
    }
};