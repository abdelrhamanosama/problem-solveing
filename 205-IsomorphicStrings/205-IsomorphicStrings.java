// Last updated: 6/10/2026, 11:49:50 AM
public class Solution {
    boolean isIsomorphic(String s, String t){ 
        return side1(s, t)&&side2(s, t);
    }
    boolean side1(String s, String t){
        char freq[] = new char[128];
        for (int i = 0; i < s.length(); i++) {
            char c1 = s.charAt(i);
            char c2 = t.charAt(i);
            if(freq[c1-0] == '\0')
                freq[c1-0] = c2;
            else if(freq[c1-0] != c2)
                return false;
        }
        return true;        
    }
    boolean side2(String s, String t){
        char freq[] = new char[128];
        for (int i = 0; i < s.length(); i++) {
            char c1 = s.charAt(i);
            char c2 = t.charAt(i);
            if(freq[c2-0] == '\0')
                freq[c2-0] = c1;
            else if(freq[c2-0] != c1)
                return false;
        }
        return true;
    }
}
