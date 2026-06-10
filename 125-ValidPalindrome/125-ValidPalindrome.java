// Last updated: 6/10/2026, 11:50:23 AM
class Solution {
    public boolean isPalindrome(String s) {
        int strat = 0 ;
        int end = s.length() - 1;
        while(strat < end)
        {
            char stratChar = s.charAt(strat);
            char endChar = s.charAt(end);
            if(!Character.isLetterOrDigit(stratChar))
                {
                    strat ++;
                    continue;
                }
            if(!Character.isLetterOrDigit(endChar))
                {
                    end--;
                    continue;
                }
            if(Character.toLowerCase(endChar) != Character.toLowerCase(stratChar))
                return false;
            strat++;
            end--;
        }
        return true;
    }
}