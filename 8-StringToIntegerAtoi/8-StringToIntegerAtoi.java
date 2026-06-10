// Last updated: 6/10/2026, 11:51:24 AM
public class Solution{
    public int myAtoi(String s) {
        int index = 0, total = 0, sing = 1;
        if(s.length()==0)return 0;
        while(s.charAt(index)==' ' &&  index < s.length()) {
            index++;
            if(index == s.length()) return 0;
        }
        if(index == s.length()) return 0;
        if(s.charAt(index)=='+'||s.charAt(index)=='-'){               
                sing = s.charAt(index)=='+'? 1:-1;
                index++;
            }
        while(index <s.length()) {
            int ch = s.charAt(index)-'0';
            if(ch<0 || ch > 9) break;
            if(Integer.MAX_VALUE/10 < total || Integer.MAX_VALUE/10 == total && ch > Integer.MAX_VALUE % 10)
                return sing==1? Integer.MAX_VALUE:Integer.MIN_VALUE;
            total = 10*total +ch;
            index++;
        }
        return total*sing;
    }
}