// Last updated: 6/10/2026, 11:51:26 AM
class Solution {
public:
    // memo[i][j] = -1 (unseen), 0 (false), 1 (true)
    vector<vector<int>> memo;
    string s;

    bool isPalin(int i, int j) {
        if (i >= j)
            return true; // base cases
        if (memo[i][j] != -1)
            return memo[i][j]; // cached

        return memo[i][j] = (s[i] == s[j]) && isPalin(i + 1, j - 1);
    }

    string longestPalindrome(string str) {
        s = str;
        int n = s.size();
        memo.assign(n, vector<int>(n, -1));
        int start = 0, maxLen = 1;

        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                if (isPalin(i, j) && j - i + 1 > maxLen) {
                    start = i;
                    maxLen = j - i + 1;
                }

        return s.substr(start, maxLen);
    }
};