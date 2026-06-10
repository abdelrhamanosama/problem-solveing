// Last updated: 6/10/2026, 12:56:44 PM
1/* صلِّ على النبي */
2#include <bits/stdc++.h>
3using namespace std;
4#define ll long long
5#define sz(s) (int)(s).size()
6#define all(s) s.begin(), s.end()
7
8class Solution
9{
10
11  //  Definition for a binary tree node.
12  // struct TreeNode {
13  //   int val;
14  //   TreeNode *left;
15  //   TreeNode *right;
16  //   TreeNode() : val(0), left(nullptr), right(nullptr) {}
17  //   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
18  //   TreeNode(int x, TreeNode *left, TreeNode *right)
19  //       : val(x), left(left), right(right) {}
20  // };
21
22private:
23  // اللهم اهدنا يا رب اليك
24  struct SparseTable
25  {
26    int n, LOG;
27    vector<vector<int>> st1, st2;
28    vector<int> lg;
29
30    // ==========================
31    // Operation
32    // ==========================
33    int operation1(int a, int b)
34    {
35      return min(a, b);
36    }
37    int operation2(int a, int b)
38    {
39      return max(a, b);
40    }
41
42    // ==========================
43    // Build
44    // ==========================
45    void build(const vector<int> &arr)
46    {
47      n = arr.size();
48
49      LOG = 1;
50      while ((1 << LOG) <= n)
51        LOG++;
52
53      st1.assign(LOG, vector<int>(n));
54      st2.assign(LOG, vector<int>(n));
55
56      lg.assign(n + 1, 0);
57      for (int i = 2; i <= n; i++)
58        lg[i] = lg[i / 2] + 1;
59
60      for (int i = 0; i < n; i++)
61      {
62        st1[0][i] = arr[i];
63        st2[0][i] = arr[i];
64      }
65
66      for (int k = 1; k < LOG; k++)
67      {
68        for (int i = 0; i + (1 << k) <= n; i++)
69        {
70
71          st1[k][i] = operation1(st1[k - 1][i],st1[k - 1][i + (1 << (k - 1))]);
72          st2[k][i] = operation2(st2[k - 1][i],st2[k - 1][i + (1 << (k - 1))]);
73        }
74      }
75    }
76
77    // ==========================
78    // Query [l , r]
79    // ==========================
80    int query1(int l, int r)
81    {
82
83      int len = r - l + 1;
84      int k = lg[len];
85
86      return operation1(
87          st1[k][l],
88          st1[k][r - (1 << k) + 1]);
89    }
90    int query2(int l, int r)
91    {
92
93      int len = r - l + 1;
94      int k = lg[len];
95
96      return operation2(
97          st2[k][l],
98          st2[k][r - (1 << k) + 1]);
99    }
100  };
101
102public:
103  int minimumIndex(vector<int>& nums) {
104        int total = 0 , cnt = 0;
105        map<int,int> mp;
106        int mx = 0;
107        for(int i = 0 ; i < nums.size(); i++)
108        { 
109          mp[nums[i]]++;
110          if(mp[mx] < mp[nums[i]]) mx = nums[i];
111        }
112        total = mp[mx];
113
114        for(int i = 0; i < sz(nums); i++){
115            if(mx == nums[i]) cnt++;
116            int lenb = i + 1, lenaf = sz(nums) - i - 1;
117            // cout<<lenb<<"\t"<<2*cnt<<"\t"<<lenaf<<"\t"<<(total - cnt) * 2 <<"\n";
118
119            if(2*cnt > lenb && (total - cnt) * 2 > lenaf) return i;
120        }
121        return  -1;
122    }
123};