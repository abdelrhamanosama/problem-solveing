// Last updated: 9/6/2026, 2:14:41 PM
class Solution {
public:
int maxActiveSectionsAfterTrade(string s)
  {
    int mx = 0;
    int cnt1 = 0;
    for(auto x:s) cnt1+=x=='1';
    vector<int> zeros;
    int i = 0;
    while(i < s.size()){
      int start = i;
      while(i < s.size() && s[i] == s[start])
        {
          i++;
        }
      if(s[start] == '0') zeros.push_back(i-start);
    }
    if(zeros.size() < 2) return cnt1;
    for(int i = 1 ; i < zeros.size(); i++)
      mx = max(mx, zeros[i] + zeros[i-1]);
    return mx + cnt1;
  }
};