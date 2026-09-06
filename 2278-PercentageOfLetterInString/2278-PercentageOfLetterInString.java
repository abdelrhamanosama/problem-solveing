// Last updated: 9/6/2026, 2:18:38 PM
class Solution {
    public int percentageLetter(String s, char letter) {
        int freq[] = new int [26];
        int size = s.length();
        for (int i = 0; i < size; i++) {
            char c = s.charAt(i);
            freq[c - 'a']++;
        }
        int percentageLetter = freq[letter-'a'];
        return (percentageLetter*100)/size;
    }
}