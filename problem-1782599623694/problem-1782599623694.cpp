// Last updated: 6/28/2026, 1:33:43 AM
1class Solution {
2public:
3long long poww(long long a, long long b)
4  {
5    if (b == 0)
6      return 1;
7    if (b == 1)
8      return a;
9    long long res = 1;
10    if (b & 1)
11      res = a;
12    long long poo = poww(a, b / 2);
13    return res * poo * poo;
14  }
15  int maximumLength(vector<int> &nums)
16  {
17    map<long long, long long> mp;
18    set<int> s;
19    for (auto x : nums)
20    {
21      s.insert(x);
22      mp[x]++;
23    }
24    int mx = 0;
25    for (auto x : s)
26    {
27      int cnt = 0;
28      if (mp[x] == 1 || x == 1)
29        {   if(mp[x] == 1)
30                cnt++;
31            else if(x == 1){
32                if(mp[x] &1) cnt = mp[x];
33                else cnt = mp[x] - 1;
34            }
35
36        }
37      else
38      {
39        long long i = 1;
40        long long res = poww(x,i);
41        cout<<res<<"\t"<<x <<"\n";
42        while (mp[res] > 1)
43          {
44            i*=2;
45            res = poww(x,i);
46          }
47        // if(mp[res] == 1)i*=2;
48        if(mp[res] == 0) i/=2;
49        if(i == 1) cnt = 1;
50        else cnt = log2(i)*2 + 1;
51      }
52      mx = max(mx, cnt);
53    }
54    return mx;
55  }
56};