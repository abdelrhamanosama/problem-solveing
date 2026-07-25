// Last updated: 7/25/2026, 5:58:40 PM
1class Solution {
2public:
3    int maxProduct(int n) {
4        int mx1 , mx2;
5        mx1 = mx2 = 0;
6        while(n){
7            int d = n%10;
8            if(d >= mx1){
9                mx2 = mx1;
10                mx1 = d ;
11            }
12            else if(d > mx2) 
13                mx2 = d;
14            n/=10;
15        }
16        return mx1*mx2;
17    }
18};