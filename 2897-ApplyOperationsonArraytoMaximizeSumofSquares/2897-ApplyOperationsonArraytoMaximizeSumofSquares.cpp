// Last updated: 10/12/2026, 2:46:17 PM
1class Solution {
2public:
3    int maxSum(vector<int>& nums, int k) {
4        vector<int> cnt(30,0);
5        long long res = 0;
6        int mod = 1e9 + 7;
7        for(int i = 0 ; i < nums.size(); i++)
8            for(int j = 29; j>= 0; j--)
9                if((nums[i] & (1<<j)))
10                cnt[j] ++;
11        
12        for(int i = 0 ; i < k; i++)
13            {
14                long long cur = 0;
15                for(int j = 29; j>= 0; j--){
16                    if(cnt[j])
17                        {
18                            cur|=((1<<j));
19                            cnt[j]--;
20                        }
21                }
22                res = (res + (cur*cur)%mod)%mod;
23            }
24        return res;
25    }
26};