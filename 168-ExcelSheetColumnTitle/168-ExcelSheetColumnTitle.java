// Last updated: 6/10/2026, 11:50:07 AM
class Solution {
    public String convertToTitle(int columnNumber) {
        String ans = "";
        while(columnNumber-- > 0)
        {
            int ch  = columnNumber % 26;
            ans += (char)(ch + 'A');
            columnNumber /= 26;
        }
        return reverseString(ans);
    }
    private String reverseString(String s)
    {
        String end = "";
        for(int  i = s.length() - 1 ;  i>= 0 ; i -- )
        {
            end += s.charAt(i); 
        }
        return end;
    }
}