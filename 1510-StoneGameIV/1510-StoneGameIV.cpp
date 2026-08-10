// Last updated: 8/10/2026, 9:19:15 PM
1class Solution {
2public:
3    int mem[202][102];
4    vector<int> suff;
5    int n;
6    int dp(int idx , int m){
7        if(idx+ 2*m >= n ) return suff[idx];
8        int &ret = mem[m][idx];
9        if(~ret) return ret;
10
11        int res = 1e9;
12        for(int i= 1; i <= 2* m; i++){
13            res = min(res , dp(idx + i , max(m , i)));
14        }
15        ret = suff[idx]-res;
16        return ret;
17    }
18    int stoneGameII(vector<int>& piles) {
19        memset(mem , -1 , sizeof mem);
20        suff = piles;
21        n = piles.size();
22        for(int i = n-1; i>0 ; i--)
23            suff[i-1]+=suff[i];
24        return dp(0,1);
25    }
26};