// Last updated: 9/6/2026, 4:01:16 PM
import java.util.Arrays;

class Solution {
    public String customSortString(String order, String s) {
        int freq[] = new int[26];
        StringBuilder sb = new StringBuilder("");
        for (int i = 0; i < s.length(); i++) {
            freq[s.charAt(i)-'a']++;
        }
        System.out.println(Arrays.toString(freq));
        for (int i = 0; i < order.length(); i++) {
            if(freq[order.charAt(i)-'a'] > 0) {
                while (freq[order.charAt(i)-'a']-->0)
                    sb.append(order.charAt(i));
            }
        }
        for (int i = 0; i < freq.length; i++) {
            if(freq[i] > 0)
                while(freq[i]-->0)
                sb.append((char)('a' + i));
        }
        return  sb.toString();

    }
}