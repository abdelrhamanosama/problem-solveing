// Last updated: 6/10/2026, 11:50:42 AM
class Solution {
    public int mySqrt(int x) {
        long  i = 0;
        if(x == 0) return 0;
        else if(x == 1 ) return 1 ;
        while(x  >=  i*i)
            i++;
        return ((int)i - 1);   
    }
}