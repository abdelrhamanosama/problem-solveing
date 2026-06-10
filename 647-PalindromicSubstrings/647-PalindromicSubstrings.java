// Last updated: 6/10/2026, 11:48:16 AM
class Solution {
    public int countSubstrings(String s) {
        StringBuilder ss =  new StringBuilder(s);
        int number = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j <= s.length()-1; j++) {
                if(plindrome(ss.substring(i, j+1).toString()))
                    number++;
            }
        }
        return number;
    }
    private static boolean plindrome(String s) {
        if(s.length() == 1)
            return true;
        else
            for (int i = 0; i < s.length()/2; i++) {
                if(s.charAt(i) != s.charAt(s.length()-i-1))
                    return false;
            }
        return true;
    }
}