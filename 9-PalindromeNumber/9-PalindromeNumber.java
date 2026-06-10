// Last updated: 6/10/2026, 11:51:22 AM
class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0)
            return false;
        else if(x == 0)
            return true;
        else
            {
                String  num = x + "";
                for(int i = 0 ; i < num.length() / 2 ; i ++)
                    if(num.charAt(i) != num.charAt(num.length() - i - 1))
                        return false ;
                    return true;
            }
    }
}