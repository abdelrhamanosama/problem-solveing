// Last updated: 6/26/2026, 5:07:23 AM
1class Solution {
2public:
3    int divide(int dividend, int divisor) {
4        if((long long)dividend /divisor  > INT32_MAX) 
5          return INT32_MAX;
6      
7          return dividend/divisor;
8    }
9};