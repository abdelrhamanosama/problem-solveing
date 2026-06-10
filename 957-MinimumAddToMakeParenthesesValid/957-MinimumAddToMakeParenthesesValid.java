// Last updated: 6/10/2026, 11:47:36 AM
class Solution {
    public int minAddToMakeValid(String s) {
        int sumup = 0;
        int extra = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == '(') {
                sumup++;
            } else {
                if (sumup > 0)
                    sumup--;
                else
                    extra++;
            }
        }
        return (sumup + extra);

    }
}