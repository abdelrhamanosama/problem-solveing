// Last updated: 7/20/2026, 7:17:47 PM
1class Solution {
2#define all(s) s.begin(), s.end()
3
4public:
5    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
6      int mx = *max_element(all(nums));
7      vector<long long> cnt(mx + 1, 0) , gcd(mx+1 , 0);
8      for(auto x:nums) cnt[x]++;
9      for(int i = mx; i > 0; i--)
10        {
11          long long sum = 0;
12          for(int j = i; j <=mx ; j+=i)
13            {
14              sum+=cnt[j];
15              gcd[i]-=gcd[j];
16            }
17            gcd[i]+=sum*(sum-1)/2;
18        }
19        
20        partial_sum(all(gcd) ,gcd.begin());
21        vector<int> ans;
22        for(auto x: queries)
23          {
24            int idx = upper_bound(all(gcd) , x) - gcd.begin();
25            ans.push_back(idx);
26          }
27        return ans;
28    }
29};