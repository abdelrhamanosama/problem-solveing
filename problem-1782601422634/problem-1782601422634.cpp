// Last updated: 6/28/2026, 2:03:42 AM
1class Solution {
2public:
3  int maximumLength(vector<int> &nums)
4  {
5    unordered_map<long long, long long> mp;
6    set<int> s;
7    for (auto x : nums)
8    {
9      s.insert(x);
10      mp[x]++;
11    }
12    long long mx = 0;
13    for (auto x : s)
14    {
15      long long cnt = 0;
16      if (mp[x] == 1 || x == 1)
17        cnt = max(1ll , (mp[x] &1 ? mp[x] : mp[x] - 1));
18      else
19      {
20        long long i = 0;
21        long long res = x;
22        while (mp[res] >= 2)
23          {
24            res *= res;  
25            i+=2;
26          }
27        if(mp[res] == 1) 
28          i++;
29        else
30          i--;
31        cnt = i;
32      }
33      mx = max(mx, cnt);
34    }
35    return mx;
36  }
37};