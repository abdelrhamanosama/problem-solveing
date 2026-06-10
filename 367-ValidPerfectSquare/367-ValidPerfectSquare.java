// Last updated: 6/10/2026, 11:49:13 AM
class Solution {
    public boolean isPerfectSquare(int num) {
        int start = 0 ,end = (int)Math.pow(Integer.MAX_VALUE,.5) , mid = 0;
        while(start <= end)
        {
            mid = (start+ end)/2;
            if(mid * mid == num)
                return true;
            else if(mid*mid > num)
                end = mid -1;
            else 
                start = mid + 1;   
        }
        return false;
    }
}