// Last updated: 6/10/2026, 11:49:51 AM
class Solution {
    private int res ;
    public boolean isHappy(int n) {
        int i  = 0;
        int last = 0;
        while(true){
            if(makeDigits(n))
                return(true);
            else
                n = res;
            if(i++ > 100 || last == res)
                return false ;
            last  = res ;

        }
    }
    private boolean makeDigits(int n)
    {
        int number = 0 , res1 = 0 ,res2 = 0;
        while(n > 0)
            {
                number = n % 10;
                n /= 10;
                res1 += number*number;
                res2 += number;
            }
        res = res1;
        return(res2 == 1);
        
    }
}