// Last updated: 9/6/2026, 4:04:20 PM
class Solution {
public:
    int n;
    vector<int> v;
    int mem[103][2];
    int dp(int i , bool f1){
        if(i >= n) return 0;
        int &ret = mem[i][f1];
        if(~ret) return ret;
        ret = 0;
        if(i == 0) 
            {
                ret = v[i] + dp(i+2 , 1);
                ret = max(ret , dp(i+1 , 0));
            }
        else if(i&&i < n-1 )
        {
            ret = max(dp(i+1 ,f1) , v[i] + dp(i+2 ,f1));
        }
        else 
            if(f1) return ret = dp(i+1,f1);
            else ret = dp(i+2 , f1) + v[i];
        return ret;
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        v = nums;
        memset(mem , -1 , sizeof mem);
        return dp(0 , 0);
    }
};