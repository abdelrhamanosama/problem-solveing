// Last updated: 8/10/2026, 6:16:55 PM
1class Solution {
2
3    List<Integer> squares;
4    Boolean[] memo;
5
6    void init(int n) {
7        squares = new ArrayList<>();
8
9        for (int i = 1; i * i <= n; i++) {
10            squares.add(i * i);
11        }
12    }
13
14    boolean dp(int n) {
15
16        // No move available -> current player loses
17        if (n == 0)
18            return false;
19
20        if (memo[n] != null)
21            return memo[n];
22
23        // Try every possible square
24        for (int square : squares) {
25
26            if (square > n)
27                break;
28
29            // If after taking this square,
30            // the opponent loses, we win.
31            if (!dp(n - square)) {
32                return memo[n] = true;
33            }
34        }
35
36        return memo[n] = false;
37    }
38
39    public boolean winnerSquareGame(int n) {
40
41        init(n);
42
43        memo = new Boolean[n + 1];
44
45        return dp(n);
46    }
47}