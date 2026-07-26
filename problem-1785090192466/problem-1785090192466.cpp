// Last updated: 7/26/2026, 9:23:12 PM
1class Solution {
2public:
3    vector<int> evenOddBit(int n) {
4       int odd = 0;
5       int even = 0;
6       int i = 0;
7        while(n){
8            int d = n&1;
9            if(i&1) odd +=  d;
10            else even +=d;
11            n>>=1;
12            i++;
13        } 
14        return {even , odd};
15    }
16};