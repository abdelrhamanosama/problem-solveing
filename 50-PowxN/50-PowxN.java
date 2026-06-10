// Last updated: 6/10/2026, 11:50:52 AM
class Solution {
    public double myPow(double x, int n) {
    double M = 1;
    DecimalFormat fmt = new DecimalFormat("0.########");
    if((n <= -Math.pow(10, 8) && (x > 1 || x < -1)) || (n >= Math.pow(10, 8) && (x < 1 && x > -1)))
        return(0);    
    if(x == 1 || (x==-1 && n%2==0))
    return(1);
    else if(x == 0)
        return(0);
    else if (x==-1 && n%2!=0)
        return(-1);    
    else     
    for(int i = 0 ; i < Math.abs(n) ; i++)
        M *= x;
    if(n<0)
         M = (Double.parseDouble(fmt.format(1 / M)));
    else
        M = (Double.parseDouble(fmt.format(M)));    
    if(M == 0 ||M ==-0 )
        return(0);
    else
        return(M);
    }    
    }
    
