// Last updated: 9/6/2026, 4:05:22 PM
class Solution {

    String s, t;
    int[][] mem = new int[1001][1001];

    int dp(int i, int j) {

        if (j == t.length())
            return 1;

        if (i == s.length())
            return 0;

        if (mem[i][j] != -1)
            return mem[i][j];

        if (s.charAt(i) == t.charAt(j)) {

            // Use s[i]
            int take = dp(i + 1, j + 1);

            // Don't use s[i]
            int skip = dp(i + 1, j);

            return mem[i][j] = take + skip;
        }

        // Characters don't match -> must skip s[i]
        return mem[i][j] = dp(i + 1, j);
    }

    public int numDistinct(String s, String t) {

        this.s = s;
        this.t = t;

        for (int i = 0; i <= s.length(); i++)
            Arrays.fill(mem[i], -1);

        return dp(0, 0);
    }
}