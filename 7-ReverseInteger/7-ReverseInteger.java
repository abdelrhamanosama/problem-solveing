// Last updated: 6/10/2026, 11:51:25 AM
class Solution {
    public int reverse(int x) {
        long num = x;
        boolean flag = (num >= 0 ) ;
        num = Math.abs(num);
        int numOfDigit = (int)Math.log10(num) + 1;
        long product = 0;
//        System.out.println(numOfDigit);
            for(int i = 1 ; i <= numOfDigit ; i++) //2147483647
                {
                    int digit = (int)(num % 10);
                    product += digit * (long)Math.pow(10 , numOfDigit - i);
                    num /= 10;
//                    System.out.println(digit + "\t" +product + " \t" + num);
                    if(product > Integer.MAX_VALUE)
                        {
                            product = 0;
                            break;                           
                        }
                }
        return((flag)? (int)product : -1 * (int)product );
    }
}