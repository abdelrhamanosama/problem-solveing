// Last updated: 9/17/2026, 10:26:41 PM
1class Solution {
2public:
3    int minOperations(int n) {
4        int ans = 0;
5        while(n > 0){
6            if((n&3) == 3){
7                n++;
8                ans++;
9            }
10            else{
11                ans+=(n&1);
12                n = n>>1;
13            }
14        }
15        return ans;
16    }
17};