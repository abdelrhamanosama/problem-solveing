// Last updated: 7/6/2026, 6:33:57 AM
1class Solution {
2public:
3int removeCoveredIntervals(vector<vector<int>>& intervals) {
4      int n = intervals.size();
5      vector<int> live(n , 1);
6      for(int i = 0 ; i < n; i++) {
7        for(int j = 0 ; j < n; j++){
8          if(i==j) continue;
9          if(intervals[i][0] <= intervals[j][0]  && intervals[i][1] >= intervals[j][1])
10            live[j] = 0;
11        }
12      }
13      int cnt = 0;
14      for(auto x:live) cnt+=x;
15      return cnt;
16    }
17};