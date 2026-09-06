// Last updated: 9/6/2026, 2:12:42 PM
class Solution {
    public int minLengthAfterRemovals(String s) {
        int a = 0, b = 0;
        for (char c : s.toCharArray()) {
            if (c == 'a')
                a++;
            else
                b++;
        }
        return Math.abs(a - b);
    }
}