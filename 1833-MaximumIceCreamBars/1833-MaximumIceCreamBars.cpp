// Last updated: 6/22/2026, 12:41:23 AM
1class Solution {
2public:
3    int maxIceCream(vector<int>& costs, int coins) {
4        multiset<int>ms;
5        for(auto x:costs) ms.insert(x);
6        int cnt = 0;
7        while(!ms.empty()&&coins >= *ms.begin()) {
8          cnt++;
9          coins-=*ms.begin();
10          ms.erase(ms.begin());
11        }
12        return cnt;
13    }
14};