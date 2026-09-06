// Last updated: 9/6/2026, 4:01:04 PM
class Solution {
public:
    bool checkThis(vector<vector<int>>& g) {
        // شرط إن الأرقام من 1 لـ 9 ومفيش تكرار
        set<int> st;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (g[i][j] < 1 || g[i][j] > 9) return false;
                st.insert(g[i][j]);
            }
        }
        if (st.size() != 9) return false;

        // تحسين: مركز الماجيك سكوير لازم يكون 5
        // if (g[1][1] != 5) return false;

        vector<int> sumr(3, 0), sumc(3, 0);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                sumr[i] += g[i][j];
                sumc[j] += g[i][j];
            }
        }

        int d1 = g[0][0] + g[1][1] + g[2][2];
        int d2 = g[0][2] + g[1][1] + g[2][0];

        set<int> s;
        s.insert(d1);
        s.insert(d2);
        for (int i = 0; i < 3; i++) {
            s.insert(sumr[i]);
            s.insert(sumc[i]);
        }

        return s.size() == 1;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int cnt = 0;

        for (int i = 0; i + 2 < n; i++) {
            for (int j = 0; j + 2 < m; j++) {
                vector<vector<int>> g(3, vector<int>(3));
                for (int r = 0; r < 3; r++) {
                    for (int c = 0; c < 3; c++) {
                        g[r][c] = grid[i + r][j + c];
                    }
                }
                cnt += checkThis(g);
            }
        }
        return cnt;
    }
};
