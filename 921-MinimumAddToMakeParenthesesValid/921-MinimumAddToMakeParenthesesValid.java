// Last updated: 9/6/2026, 4:00:47 PM
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