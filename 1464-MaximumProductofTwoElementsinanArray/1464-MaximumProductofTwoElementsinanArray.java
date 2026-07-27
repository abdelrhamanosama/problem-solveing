// Last updated: 7/27/2026, 3:29:57 AM
1class Solution {
2    public int maxProduct(int[] nums) {
3        int mx1 = 0 ,mx2 = 0;
4        for(int i: nums){
5            if(mx1 < i){
6                mx2 = mx1;
7                mx1 = i;
8            }
9            else if(mx2 < i) 
10                mx2 = i;
11
12        }
13        return (mx1-1)*(mx2-1);
14    }
15}