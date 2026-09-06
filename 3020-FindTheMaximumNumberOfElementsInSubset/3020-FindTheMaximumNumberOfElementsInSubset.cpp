// Last updated: 9/6/2026, 2:16:19 PM
class Solution {
public:
  int maximumLength(vector<int> &nums)
  {
    unordered_map<long long, long long> mp;
    set<int> s;
    for (auto x : nums)
    {
      s.insert(x);
      mp[x]++;
    }
    long long mx = 0;
    for (auto x : s)
    {
      long long cnt = 0;
      if (mp[x] == 1 || x == 1)
        cnt = max(1ll , (mp[x] &1 ? mp[x] : mp[x] - 1));
      else
      {
        long long i = 0;
        long long res = x;
        while (mp[res] >= 2)
          {
            res *= res;  
            i+=2;
          }
        if(mp[res] == 1) 
          i++;
        else
          i--;
        cnt = i;
      }
      mx = max(mx, cnt);
    }
    return mx;
  }
};