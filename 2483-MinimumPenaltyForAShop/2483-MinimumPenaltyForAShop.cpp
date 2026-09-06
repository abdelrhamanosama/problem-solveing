// Last updated: 9/6/2026, 2:18:17 PM
class Solution {
public:
    int bestClosingTime(string customers) {
        int N = (customers.size());
        int y = 0, n = 0;
        for (auto x : customers) {
            if (x == 'Y')
                y++;
        }
        // cout<<y<<"\n";
        int mn = 1e9, idx = 0;
        for (int i = 0; i <= N; i++) {
            if (mn > y + n) {
                mn = y + n;
                idx = i;
                // cout<<mn<<"\n";
            }
            if (i == N)
                break;
            if (customers[i] == 'Y')
                y--;
            else
                n++;
        }
        return idx;
    }
};