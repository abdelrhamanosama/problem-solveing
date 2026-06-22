// Last updated: 6/22/2026, 3:21:08 AM
1class Solution {
2#define all(s) s.begin(), s.end()
3
4public:
5    int maxBuilding(int n, vector<vector<int>>& restrictions) {
6      restrictions.push_back({1,0});
7      sort(all(restrictions));
8      if(restrictions.back()[0] != n) restrictions.push_back({n,n-1});
9      int mx = 0 , m = restrictions.size();
10      for(int i = 1; i<m; i++){
11          restrictions[i][1] = min(restrictions[i][1] , restrictions[i-1][1] + (restrictions[i][0] - restrictions[i-1][0]));
12      }
13      for(int i = m-2; i >=0 ; i--)
14          restrictions[i][1] = min(restrictions[i][1] , restrictions[i+1][1] + (restrictions[i+1][0] - restrictions[i][0]));
15      for(int i = 1 ; i < m; i++){
16        if(restrictions[i-1][1] < restrictions[i][1]){
17            int s = restrictions[i-1][0] + (restrictions[i][1] - restrictions[i-1][1]);
18            int diff = restrictions[i][0] - s;
19            int ans = diff/2 + restrictions[i][1];
20            mx = max(mx , ans);
21        }
22        else if(restrictions[i-1][1] == restrictions[i][1]){
23          int diff = restrictions[i][0] - restrictions[i-1][0];
24          int ans = diff/2 + restrictions[i][1];
25          mx = max(mx , ans);
26        }
27        else {
28            int s = restrictions[i-1][0] + (restrictions[i-1][1] - restrictions[i][1]);
29            int diff = restrictions[i][0] - s;
30            int ans = diff/2 + restrictions[i-1][1];
31            mx = max(mx , ans);
32        }
33      }
34
35      
36      return mx;
37    }
38    
39};