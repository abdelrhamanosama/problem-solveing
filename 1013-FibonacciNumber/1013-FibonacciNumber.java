// Last updated: 6/10/2026, 11:47:25 AM
class Solution {
    public int fib(int n) {
        if(n == 0)
            return 0;
        else if(n == 1)
            return 1;
        else 
            return(fib(n-1)+fib(n-2));
    }
}