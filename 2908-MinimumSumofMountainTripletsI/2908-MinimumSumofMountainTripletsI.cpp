// Last updated: 7/23/2026, 12:36:41 AM
1/* صلِّ على النبي */
2#include <bits/stdc++.h>
3
4#include <ext/pb_ds/assoc_container.hpp>
5using namespace __gnu_pbds;
6using namespace std;
7#define ll long long
8#define sz(s) (int)(s).size()
9#define all(s) s.begin(), s.end()
10
11class Solution
12{
13
14private:
15  // اللهم اهدنا يا رب اليك
16  struct SparseTable
17  {
18    int n, LOG;
19    vector<vector<int>> st1, st2;
20    vector<int> lg;
21
22    // ==========================
23    // Operation
24    // ==========================
25    int operation1(int a, int b)
26    {
27      return min(a, b);
28    }
29    int operation2(int a, int b)
30    {
31      return max(a, b);
32    }
33
34    // ==========================
35    // Build
36    // ==========================
37    void build(const vector<int> &arr)
38    {
39      n = arr.size();
40
41      LOG = 1;
42      while ((1 << LOG) <= n)
43        LOG++;
44
45      st1.assign(LOG, vector<int>(n));
46      st2.assign(LOG, vector<int>(n));
47
48      lg.assign(n + 1, 0);
49      for (int i = 2; i <= n; i++)
50        lg[i] = lg[i / 2] + 1;
51
52      for (int i = 0; i < n; i++)
53      {
54        st1[0][i] = arr[i];
55        st2[0][i] = arr[i];
56      }
57
58      for (int k = 1; k < LOG; k++)
59      {
60        for (int i = 0; i + (1 << k) <= n; i++)
61        {
62
63          st1[k][i] = operation1(st1[k - 1][i], st1[k - 1][i + (1 << (k - 1))]);
64          st2[k][i] = operation2(st2[k - 1][i], st2[k - 1][i + (1 << (k - 1))]);
65        }
66      }
67    }
68
69    // ==========================
70    // Query [l , r]
71    // ==========================
72    int query1(int l, int r)
73    {
74
75      int len = r - l + 1;
76      int k = lg[len];
77
78      return operation1(
79          st1[k][l],
80          st1[k][r - (1 << k) + 1]);
81    }
82    int query2(int l, int r)
83    {
84
85      int len = r - l + 1;
86      int k = lg[len];
87
88      return operation2(
89          st2[k][l],
90          st2[k][r - (1 << k) + 1]);
91    }
92  };
93
94public:
95    int minimumSum(vector<int>& nums) {
96      SparseTable sp;
97      sp.build(nums);
98      int mn = 1e9;
99      for(int i = 1; i < nums.size()-1; i++){
100        int v1 = sp.query1(0,i-1);
101        int v2 = sp.query1(i+1 , nums.size()-1);
102        if(v1 < nums[i] && v2 < nums[i])
103        mn = min(mn , v1+v2+nums[i]);
104      } 
105      return (mn == 1e9 ? -1 : mn);   
106    }
107};