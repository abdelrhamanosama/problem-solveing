// Last updated: 6/10/2026, 11:50:41 AM
class Solution {
    public int climbStairs(int n) {
        int f1 = 1 , f2 = 1;
        int num = 0;
        if(n == 0 || n == 1)
            return 1;
        else 
        {
            for(int i = 2 ; i <= n ; i ++)
                {
                    num = f1 + f2;
                    f2 = f1;
                    f1 = num;
                }
        }
        return num;

    }    
}