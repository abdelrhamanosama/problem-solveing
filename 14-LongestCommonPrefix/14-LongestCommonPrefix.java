// Last updated: 6/10/2026, 11:51:17 AM
public class Solution {
    public String longestCommonPrefix(String[] strs) {
        String s1 = "", s2 = "";
        try {
            for (int i = 0; i < strs[0].length(); i++) {
                boolean flag = false;
                for (int j = 1; j < strs.length; j++) {
                    if (strs[0].charAt(i) != strs[j].charAt(i)) {
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                    s1 += strs[0].charAt(i);
                else {
                    break;
                }
            }
        }
        catch (Exception e)
        {}
        return s1;
    }
}
