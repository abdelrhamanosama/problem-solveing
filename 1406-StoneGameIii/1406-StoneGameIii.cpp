// Last updated: 9/6/2026, 2:25:09 PM
class Solution {
    int n;
    vector<int> stone;
    int memo[50005][2];

    int dp(int i, bool bobTurn) {
        if (i >= n)
            return 0;

        int &ret = memo[i][bobTurn];
        if (ret != INT_MIN)
            return ret;

        ret = bobTurn ? INT_MAX : INT_MIN;

        int sum = 0;
        for (int take = 1; take <= 3 && i + take - 1 < n; take++) {
            sum += stone[i + take - 1];

            int cur = dp(i + take, !bobTurn);

            if (bobTurn)
                ret = min(ret, cur - sum);
            else
                ret = max(ret, cur + sum);
        }

        return ret;
    }

public:
    string stoneGameIII(vector<int>& stoneValue) {
        stone = stoneValue;
        n = stone.size();

        for (int i = 0; i <= n; i++)
            memo[i][0] = memo[i][1] = INT_MIN;

        int diff = dp(0, false);

        if (diff > 0) return "Alice";
        if (diff < 0) return "Bob";
        return "Tie";
    }
};