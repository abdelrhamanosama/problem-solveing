// Last updated: 6/10/2026, 11:51:32 AM
public class Solution {
    public int lengthOfLongestSubstring(String s) {
        String temp = "" ,help = "";
        int max = 0;//"jbpnbwwd"
        if(s.length() == 1) return (1);
        for(int i = 0 ; i < s.length() - 1; i++)
                for (int j = i ; j < s.length() ; j++)
                    {   help += s.charAt(j);
                        if(!temp.contains(help))
                            temp +=  s.charAt(j);
                        else
                        {
                            temp = "";
                            break;
                        }
                        if(max < temp.length())
                            max = temp.length();
                        help = "";
                    }
        return (max);
    }
}