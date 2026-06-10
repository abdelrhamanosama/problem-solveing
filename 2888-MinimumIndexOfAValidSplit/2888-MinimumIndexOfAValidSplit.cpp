// Last updated: 6/10/2026, 12:58:05 PM
/* صلِّ على النبي */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(s) (int)(s).size()
#define all(s) s.begin(), s.end()

class Solution
{

  //  Definition for a binary tree node.
  // struct TreeNode {
  //   int val;
  //   TreeNode *left;
  //   TreeNode *right;
  //   TreeNode() : val(0), left(nullptr), right(nullptr) {}
  //   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  //   TreeNode(int x, TreeNode *left, TreeNode *right)
  //       : val(x), left(left), right(right) {}
  // };

private:
  // اللهم اهدنا يا رب اليك
  struct SparseTable
  {
    int n, LOG;
    vector<vector<int>> st1, st2;
    vector<int> lg;

    // ==========================
    // Operation
    // ==========================
    int operation1(int a, int b)
    {
      return min(a, b);
    }
    int operation2(int a, int b)
    {
      return max(a, b);
    }

    // ==========================
    // Build
    // ==========================
    void build(const vector<int> &arr)
    {
      n = arr.size();

      LOG = 1;
      while ((1 << LOG) <= n)
        LOG++;

      st1.assign(LOG, vector<int>(n));
      st2.assign(LOG, vector<int>(n));

      lg.assign(n + 1, 0);
      for (int i = 2; i <= n; i++)
        lg[i] = lg[i / 2] + 1;

      for (int i = 0; i < n; i++)
      {
        st1[0][i] = arr[i];
        st2[0][i] = arr[i];
      }

      for (int k = 1; k < LOG; k++)
      {
        for (int i = 0; i + (1 << k) <= n; i++)
        {

          st1[k][i] = operation1(st1[k - 1][i],st1[k - 1][i + (1 << (k - 1))]);
          st2[k][i] = operation2(st2[k - 1][i],st2[k - 1][i + (1 << (k - 1))]);
        }
      }
    }

    // ==========================
    // Query [l , r]
    // ==========================
    int query1(int l, int r)
    {

      int len = r - l + 1;
      int k = lg[len];

      return operation1(
          st1[k][l],
          st1[k][r - (1 << k) + 1]);
    }
    int query2(int l, int r)
    {

      int len = r - l + 1;
      int k = lg[len];

      return operation2(
          st2[k][l],
          st2[k][r - (1 << k) + 1]);
    }
  };

public:
  int minimumIndex(vector<int>& nums) {
        int total = 0 , cnt = 0;
        map<int,int> mp;
        int mx = 0;
        for(int i = 0 ; i < nums.size(); i++)
        { 
          mp[nums[i]]++;
          if(mp[mx] < mp[nums[i]]) mx = nums[i];
        }
        total = mp[mx];

        for(int i = 0; i < sz(nums); i++){
            if(mx == nums[i]) cnt++;
            int lenb = i + 1, lenaf = sz(nums) - i - 1;
            // cout<<lenb<<"\t"<<2*cnt<<"\t"<<lenaf<<"\t"<<(total - cnt) * 2 <<"\n";

            if(2*cnt > lenb && (total - cnt) * 2 > lenaf) return i;
        }
        return  -1;
    }
};