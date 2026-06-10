// Last updated: 6/10/2026, 11:48:12 AM
class Solution {
    public boolean validPalindrome(String s) {
        int strat  = 0 ;
        int end  = s.length() - 1;
        while(strat < end)
        {
            if(s.charAt(end) != s.charAt(strat))
                return(isPalindrome(s,strat + 1,end) || isPalindrome(s, strat, end - 1));
            strat++;
            end--;
        }
        return true;
    }
    public boolean isPalindrome(String s , int Strat , int End) {
        // System.out.println(s);
        // System.out.println("-------------");
        int strat = Strat ;
        int end = End;
        while(strat < end)
        {
            if(s.charAt(end) != s.charAt(strat))
                return false;
            strat++;
            end--;
        }
        return true;
    }
}
