// Last updated: 6/10/2026, 11:48:28 AM
class Solution {
    public boolean judgeSquareSum(int c) {
        int i = 0 ;
        boolean falge = false;
        while(!falge)
            {
                if(c - i * i < 0) return false;
                falge = checksquare(c - i * i);   
                if(i > 46340 && falge ==false)
                    break;
                    i++;
            }
            return(falge);
    }
  private  boolean checksquare(int x)
    {   

        double y = Math.pow(x,0.5) ;
        x = (int)y;
        y = y - x ;
        if(y != 0)
            return false;
        else
            return true;
    }
}