// Last updated: 9/6/2026, 4:03:42 PM
class Solution {
public:
    int n;
    vector<int> v;
    int mem[5002][1003][2];
    int dp(int i , int f1 , bool bought){
        if(i >= n) return 0;
        int &ret = mem[i][f1][bought];
        if(~ret) return ret;
        ret = 0;
        if(!i){
            ret = max(dp(i+1 , f1 , 0) , dp(i+1 , v[i],1));
        }
        else {
            if(bought){
                if(f1 < v[i])
                    ret = dp(i+2 , 0 , 0) + v[i] - f1;
            }
            else {
                ret = dp(i+1,v[i] , 1);
            }
                ret = max(ret , dp(i+1,f1 , bought));
        }
        return ret;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        v = prices;
        memset(mem , -1 , sizeof mem);
        return dp(0 , 0 , 0);  
    }
};

