// Last updated: 9/6/2026, 2:12:55 PM
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
  long long maxTotalValue(vector<int> &nums, int k)
  {
      ll sum = 0;
      priority_queue<array<ll,3>>pq;
      pq.push({0,0,0});
      SparseTable sp;
      sp.build(nums);
      int i = 0 , j = 0  , n = nums.size();
      for(int i = 0 ; i < nums.size(); i++){
        pq.push({sp.query2(i,n-1) - sp.query1(i, n-1) , i , n-1});
      }
      while(k --)
        {
          auto[val , l , r] = pq.top();
          sum +=val;
          pq.pop();
          if(r > l) 
            pq.push({sp.query2(l,r-1) - sp.query1(l, r-1) , l , r-1});

        }

      return sum;
  }
};