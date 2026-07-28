// Last updated: 7/28/2026, 3:20:39 PM
1class Solution {
2public:
3    int n;
4    vector<int> v;
5    int mem[5002][1003][2];
6    int dp(int i , int f1 , bool bought){
7        if(i >= n) return 0;
8        int &ret = mem[i][f1][bought];
9        if(~ret) return ret;
10        ret = 0;
11        if(!i){
12            ret = max(dp(i+1 , f1 , 0) , dp(i+1 , v[i],1));
13        }
14        else {
15            if(bought){
16                if(f1 < v[i])
17                    ret = dp(i+2 , 0 , 0) + v[i] - f1;
18            }
19            else {
20                ret = dp(i+1,v[i] , 1);
21            }
22                ret = max(ret , dp(i+1,f1 , bought));
23        }
24        return ret;
25    }
26    int maxProfit(vector<int>& prices) {
27        n = prices.size();
28        v = prices;
29        memset(mem , -1 , sizeof mem);
30        return dp(0 , 0 , 0);  
31    }
32};
33
34