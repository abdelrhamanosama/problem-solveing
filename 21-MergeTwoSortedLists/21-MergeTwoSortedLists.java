// Last updated: 8/10/2026, 11:32:40 PM
1class Solution {
2    public char findKthBit(int n, int k) {
3       if(n == 1)  return '0';
4    
5        int len  = (1<<n) - 1;
6        int mid  = (len+1)/2;
7
8        if(mid == k) return '1';
9        if(k < mid) return findKthBit(n-1,k);
10
11        char c = findKthBit(n-1,len-k+1);
12        return c == '0'? '1':'0';
13    }
14}