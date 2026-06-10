// Last updated: 6/10/2026, 11:43:11 AM
class Solution {
    public boolean isSameAfterReversals(int num) {
        return (num == reverse(reverse(num)));
    }
    public int reverse(int num) {
        num = Math.abs(num);
        int numOfDigit = (int)Math.log10(num) + 1;
        int product = 0;
            for(int i = 1 ; i <= numOfDigit ; i++) //2147483647
                {
                    int digit = (num % 10);
                    product += digit * (int)Math.pow(10 , numOfDigit - i);
                    num /= 10;
                }
        return(product);
    }

}