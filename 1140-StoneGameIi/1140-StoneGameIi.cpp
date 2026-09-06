// Last updated: 9/6/2026, 3:59:42 PM
class Solution {
public:
    int mem[202][102];
    vector<int> suff;
    int n;
    int dp(int idx , int m){
        if(idx+ 2*m >= n ) return suff[idx];
        int &ret = mem[m][idx];
        if(~ret) return ret;

        int res = 1e9;
        for(int i= 1; i <= 2* m; i++){
            res = min(res , dp(idx + i , max(m , i)));
        }
        ret = suff[idx]-res;
        return ret;
    }
    int stoneGameII(vector<int>& piles) {
        memset(mem , -1 , sizeof mem);
        suff = piles;
        n = piles.size();
        for(int i = n-1; i>0 ; i--)
            suff[i-1]+=suff[i];
        return dp(0,1);
    }
};