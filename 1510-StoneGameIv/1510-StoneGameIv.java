// Last updated: 9/6/2026, 2:23:55 PM
class Solution {

    List<Integer> squares;
    Boolean[] memo;

    void init(int n) {
        squares = new ArrayList<>();

        for (int i = 1; i * i <= n; i++) {
            squares.add(i * i);
        }
    }

    boolean dp(int n) {

        // No move available -> current player loses
        if (n == 0)
            return false;

        if (memo[n] != null)
            return memo[n];

        // Try every possible square
        for (int square : squares) {

            if (square > n)
                break;

            // If after taking this square,
            // the opponent loses, we win.
            if (!dp(n - square)) {
                return memo[n] = true;
            }
        }

        return memo[n] = false;
    }

    public boolean winnerSquareGame(int n) {

        init(n);

        memo = new Boolean[n + 1];

        return dp(n);
    }
}