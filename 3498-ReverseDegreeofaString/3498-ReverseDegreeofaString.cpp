// Last updated: 9/20/2026, 12:42:58 PM
1class Solution {
2public:
3    int reverseDegree(string s) {
4        int sum = 0;
5        int i = 1;
6        for(auto x:s){
7            int idx = x-'a'+1;
8            int revIdx = 26-idx+1;
9            sum+=i*revIdx;
10            i++;
11        }
12        return sum;
13    }
14};