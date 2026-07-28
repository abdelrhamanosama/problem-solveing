// Last updated: 7/28/2026, 2:56:57 PM
1class Solution {
2public:
3    int n;
4    vector<int> v;
5    int mem[103][2];
6    int dp(int i , bool f1){
7        if(i >= n) return 0;
8        int &ret = mem[i][f1];
9        if(~ret) return ret;
10        ret = 0;
11        if(i == 0) 
12            {
13                ret = v[i] + dp(i+2 , 1);
14                ret = max(ret , dp(i+1 , 0));
15            }
16        else if(i&&i < n-1 )
17        {
18            ret = max(dp(i+1 ,f1) , v[i] + dp(i+2 ,f1));
19        }
20        else 
21            if(f1) return ret = dp(i+1,f1);
22            else ret = dp(i+2 , f1) + v[i];
23        return ret;
24    }
25    int rob(vector<int>& nums) {
26        n = nums.size();
27        v = nums;
28        memset(mem , -1 , sizeof mem);
29        return dp(0 , 0);
30    }
31};