// Last updated: 6/10/2026, 11:49:29 AM
class Solution {
    public int addDigits(int num) {
        while(num > 0)
        {
            int copy = num;
            int sec = 0;
            while(copy > 0)
            {
                sec += copy % 10;
                copy /= 10;
            }
            if(sec < 10)
                return sec;
            num = sec ;
        }
        return 0;
    }
}