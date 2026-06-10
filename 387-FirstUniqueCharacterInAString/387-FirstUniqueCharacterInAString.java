// Last updated: 6/10/2026, 11:49:10 AM
class Solution {
    public int firstUniqChar(String s) {
        int []ar = new int[26];
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            ar[ch - 'a']++;
        }
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if(ar[ch-'a']==1)
                return i;
        }
        return -1;
    }
}