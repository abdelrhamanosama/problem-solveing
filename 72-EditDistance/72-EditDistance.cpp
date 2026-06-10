// Last updated: 6/10/2026, 11:50:39 AM
class Solution {
public:
    string a, b;
    int mem[505][505];

    int dp(int i, int j) {
        if (i == a.size()) return b.size() - j;  // need to insert the rest
        if (j == b.size()) return a.size() - i;  // need to delete the rest
        
        if (mem[i][j] != -1) return mem[i][j];

        if (a[i] == b[j]) 
            return mem[i][j] = dp(i + 1, j + 1);

        int insertOp = dp(i, j + 1);     // insert b[j] into a
        int deleteOp = dp(i + 1, j);     // delete a[i]
        int replaceOp = dp(i + 1, j + 1); // replace a[i] with b[j]

        return mem[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
    }

    int minDistance(string word1, string word2) {
        a = word1;
        b = word2;
        memset(mem, -1, sizeof(mem));
        return dp(0, 0);
    }
};
