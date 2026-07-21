// Last updated: 7/22/2026, 12:36:40 AM
1class Solution {
2public:
3int maxActiveSectionsAfterTrade(string s)
4  {
5    int mx = 0;
6    int cnt1 = 0;
7    for(auto x:s) cnt1+=x=='1';
8    vector<int> zeros;
9    int i = 0;
10    while(i < s.size()){
11      int start = i;
12      while(i < s.size() && s[i] == s[start])
13        {
14          i++;
15        }
16      if(s[start] == '0') zeros.push_back(i-start);
17    }
18    if(zeros.size() < 2) return cnt1;
19    for(int i = 1 ; i < zeros.size(); i++)
20      mx = max(mx, zeros[i] + zeros[i-1]);
21    return mx + cnt1;
22  }
23};