// Last updated: 6/10/2026, 11:51:03 AM
class Solution {
    public int strStr(String haystack, String needle) {
        int  i , size = needle.length(); 
        boolean flag = false;
        if(haystack.length() == needle.length())
            {
                if(haystack.equalsIgnoreCase(needle))
                    return 0;
                else
                    return -1;
            }
        for(i = 0 ; i <= haystack.length() - needle.length() ; i++)
            if(haystack.substring(i, i + size).equalsIgnoreCase(needle))
                {
                    flag = true;  break;
                }
        if(flag)
             return i;
        return -1;
    }
}