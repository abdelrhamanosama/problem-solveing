// Last updated: 6/10/2026, 11:49:27 AM
class Solution {
    public boolean isUgly(int n) {
        if(n <= 0)
            return false;
        while(true)
        {
            if(n == 1)
                break;
            else if(n % 2 == 0)
                n /= 2;
            else if(n % 3 == 0)
                n /= 3;
            else if(n % 5 == 0)
                n /= 5;
            else 
                return false;
        }
        return true;        
    }
}