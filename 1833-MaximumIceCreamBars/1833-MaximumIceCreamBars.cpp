// Last updated: 6/22/2026, 12:58:56 AM
1class Solution {
2public:
3    int maxIceCream(vector<int>& costs, int coins) {
4        long long arr[100002] = { };
5        long long sum = 0,cnt = 0;
6        for(int x : costs) arr[x]++;
7        for(int i = 1 ; i <= 100000; i++) {
8            if(sum + arr[i]*i <= coins){
9              sum+=(arr[i]*i);
10              cnt+=arr[i];
11            }
12            else if(floor((coins-sum)/i) >0) {
13              cnt+=floor((coins-sum)/i);
14              break;
15            }
16            else 
17              break;
18        }
19        return cnt;
20    }
21};