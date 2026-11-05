// Last updated: 11/4/2026, 6:38:05 AM
1class Solution {
2    public int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
3      int cnt=0;
4      for(int i= 0;i <arr1.length;i++)
5      {
6        boolean flag = false;
7        for(int j= 0;j <arr2.length;j++)
8            if(Math.abs(arr1[i]-arr2[j])<=d) flag = true;
9        if(!flag) cnt++;
10      }
11        return cnt;
12    }
13}