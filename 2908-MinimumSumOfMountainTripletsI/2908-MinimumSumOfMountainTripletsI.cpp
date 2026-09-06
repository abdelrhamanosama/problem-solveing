// Last updated: 9/6/2026, 2:16:45 PM
/* صلِّ على النبي */
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define sz(s) (int)(s).size()
#define all(s) s.begin(), s.end()

class Solution
{

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

          st1[k][i] = operation1(st1[k - 1][i], st1[k - 1][i + (1 << (k - 1))]);
          st2[k][i] = operation2(st2[k - 1][i], st2[k - 1][i + (1 << (k - 1))]);
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
    int minimumSum(vector<int>& nums) {
      SparseTable sp;
      sp.build(nums);
      int mn = 1e9;
      for(int i = 1; i < nums.size()-1; i++){
        int v1 = sp.query1(0,i-1);
        int v2 = sp.query1(i+1 , nums.size()-1);
        if(v1 < nums[i] && v2 < nums[i])
        mn = min(mn , v1+v2+nums[i]);
      } 
      return (mn == 1e9 ? -1 : mn);   
    }
};