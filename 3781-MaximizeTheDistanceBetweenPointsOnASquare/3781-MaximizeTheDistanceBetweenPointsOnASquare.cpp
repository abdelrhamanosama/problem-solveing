// Last updated: 6/10/2026, 11:41:39 AM
class Solution {
public:
#define all(s) s.begin(), s.end()
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> arr;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            int x = points[i][0], y = points[i][1];
            if (x == 0)
                arr.push_back(y);
            else if (y == side)
                arr.push_back(side + x);
            else if (x == side)
                arr.push_back(2ll * side + (side - y));
            else
                arr.push_back(3ll * side + side - x);
        }
        sort(all(arr));
        auto check = [=](int max) -> bool {
            for (auto x : arr) {
                long long endo = x + 4ll * side - max;
                long long starto = x;
                bool flag = 1;
                for (int i = 0; i < k - 1; i++) {
                    auto y = lower_bound(all(arr), starto + max);
                    if (y == arr.end() || *y > endo) {
                        flag = 0;
                        break;
                    }
                    starto = *y;
                }
                if (flag)
                    return 1;
            }
            return 0;
        };
        long long l = 0, h = side, ans = 0;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (check(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return ans;
    }
};