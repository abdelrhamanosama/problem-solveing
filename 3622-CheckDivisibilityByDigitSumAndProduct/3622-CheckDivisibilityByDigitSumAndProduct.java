// Last updated: 9/6/2026, 2:13:40 PM
class Solution {
    public boolean checkDivisibility(int n) {
        int prod = 1 , sum = 0 ,save = n;
        while(n > 0) {
            int digit = n%10;
            n/=10;
            prod*=digit;
            sum+=digit;
        } 
        return (save%(sum+prod) == 0 ? true : false);
    }
}