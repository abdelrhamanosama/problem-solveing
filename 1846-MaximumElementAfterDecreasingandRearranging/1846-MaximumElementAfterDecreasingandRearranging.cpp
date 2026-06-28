// Last updated: 6/28/2026, 6:25:51 PM
1class Solution {
2public:
3        int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
4      multiset<int> s;
5      for(auto x: arr) s.insert(x);
6      int mx = 0;
7      
8      while(!s.empty()){
9          auto it = s.lower_bound(mx);
10          int val = *it;
11          if(val != mx) {
12            mx ++;
13
14          }
15          s.erase(it);
16      }
17      return mx;
18    }
19  
20};