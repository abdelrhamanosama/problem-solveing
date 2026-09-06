// Last updated: 9/6/2026, 2:14:43 PM
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
        if (l > r) return 0;
      int len = r - l + 1;
      int k = lg[len];

      return operation2(
          st2[k][l],
          st2[k][r - (1 << k) + 1]);
    }
  };

public:
      vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int cnt1 = 0;
        for(auto x: s) cnt1+=(x=='1');
        vector<int> blockZeros;
        vector<int> leftBlocks;
        vector<int> rightBlocks;
        int i = 0;
        while(i < n){
          int start = i;
          while(i < n && s[i] == s[start]) i++;
          if(s[start] == '0'){
            blockZeros.push_back(i-start);
            leftBlocks.push_back(start);
            rightBlocks.push_back(i-1);
          }
        }
        int m = blockZeros.size();
        vector<int> ans(queries.size(),cnt1);
        if(m<2){
          return ans;
        }
        vector<int> sum(m-1,0);
        for(int i = 1 ; i < m; i++) sum[i-1]= blockZeros[i] + blockZeros[i-1];
        
        SparseTable sp; 
        sp.build(sum);
        int idx = 0;
        for(auto x: queries){
          int l = x[0],r =x[1];
          int i = lower_bound(all(rightBlocks) , l)-rightBlocks.begin();
          int j = upper_bound(all(leftBlocks) , r)-leftBlocks.begin()-1;
          if(i > m-1 || j < 0 || i>= j ) {
            idx++;
            continue;
          }
        //   cout<<l <<" "<<r<<" "<<i<<" "<<r<<"\n";
          int firstLen = rightBlocks[i]-max(leftBlocks[i] , l) + 1;
          int lastLen =  min(rightBlocks[j] , r) - leftBlocks[j] +1;
          if(i+1 == j){
            ans[idx++] +=  firstLen+lastLen;
            continue;
          }
          int val1 = firstLen + blockZeros[i+1];
          int val2 = lastLen + blockZeros[j-1];
          int val3 = sp.query2(i+1,j-2);
          int best = max({val1 ,val2 ,val3});
          ans[idx++] += best;
        }
        return ans;
    }
};