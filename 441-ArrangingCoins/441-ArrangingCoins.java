// Last updated: 6/10/2026, 11:49:03 AM
class Solution {
        public int arrangeCoins(int n) {
                long x = 0 ,i = 1;
                while(true) {
                        x+=i;
                        if(x == n) return(int)(i);
                        if(n < x)  return(int)(i - 1);
                        i++;
                }
        }
}
/*
        8 7 4
 */