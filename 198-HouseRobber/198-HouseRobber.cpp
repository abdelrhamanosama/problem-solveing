// Last updated: 6/10/2026, 11:49:54 AM
class Solution {
public:
    int n;
    vector<int> v;
    int mem[103];
    int dp(int i ){
        if(i >= n) return 0;
        int &ret = mem[i];
        if(~ret) return ret;
        ret = 0;
        ret = max(dp(i+1) , v[i] + dp(i+2));
        return ret;
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        v = nums;
        memset(mem , -1 , sizeof mem);
        return dp(0);
    }
};