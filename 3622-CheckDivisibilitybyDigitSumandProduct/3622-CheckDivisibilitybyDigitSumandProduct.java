// Last updated: 8/22/2026, 11:23:03 PM
1class Solution {
2    public boolean checkDivisibility(int n) {
3        int prod = 1 , sum = 0 ,save = n;
4        while(n > 0) {
5            int digit = n%10;
6            n/=10;
7            prod*=digit;
8            sum+=digit;
9        } 
10        return (save%(sum+prod) == 0 ? true : false);
11    }
12}