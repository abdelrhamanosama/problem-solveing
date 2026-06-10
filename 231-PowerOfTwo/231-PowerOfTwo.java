// Last updated: 6/10/2026, 11:49:38 AM
class Solution {
    public boolean isPowerOfTwo(int n) {
        if(n < 0) return false;
        double power = Math.log10(n) / Math.log10(2);
        int power2 = (int)power;
        return(power == power2);          
    }
}