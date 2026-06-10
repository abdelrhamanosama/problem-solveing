// Last updated: 6/10/2026, 11:49:17 AM
class Solution {
    public boolean isPowerOfFour(int n) {
        if(n < 0) return false;
        double power = Math.log10(n) / Math.log10(4);
        int power2 = (int)power;
        return(power == power2);          
    }
}