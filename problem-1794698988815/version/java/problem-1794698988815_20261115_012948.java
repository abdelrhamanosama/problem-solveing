// Last updated: 11/15/2026, 1:29:48 AM
1class Solution {
2    public long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
3      // max of need * cost both
4      // cost1*need1 + cost2*need2
5      // costboth*min + rem*cost of rem
6      long  t1 = (long)Math.max(need1 , need2)*costBoth;
7      long t2 = (long)cost1*need1 + (long)cost2*need2;
8      long t3 = (long)Math.min(need1 , need2)*costBoth +  ((need1>=need2)?(long)(need1-need2)*cost1:(long)(need2-need1)*cost2);
9      return Math.min(t1 , Math.min(t2,t3)); 
10    }
11}