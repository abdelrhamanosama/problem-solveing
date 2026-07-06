// Last updated: 7/6/2026, 6:43:24 AM
1class Solution {
2#define all(s) s.begin(), s.end()
3
4public:
5int removeCoveredIntervals(vector<vector<int>>& intervals) {
6     ranges::sort(intervals, {}, [](auto& x) {
7            return pair{x[0], -x[1]};
8        });
9      int cnt = 0;
10      int mx = 0;
11      for(int i = 0 ; i < intervals.size() ; i++){
12        cnt+= mx >= intervals[i][1];
13        mx = max(mx  , intervals[i][1]);
14      }
15      return intervals.size()-cnt;
16    }
17};