// Last updated: 6/10/2026, 11:41:41 AM
class Solution {
public:
    double check(double mid, vector<vector<int>>& squares) {
        double area = 0.0;
        for (auto &x : squares) {
            double y = x[1];
            double side = x[2];

            if (mid <= y) {
                // الخط تحت المربع → لا مساحة
                continue;
            }
            else if (mid >= y + side) {
                // الخط فوق المربع → مساحة كاملة
                area += side * side;
            }
            else {
                // الخط قاطع المربع
                area += (mid - y) * side;
            }
        }
        return area;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double total = 0.0;
        for (auto &x : squares) {
            total += 1.0 * x[2] * x[2];
        }

        double l = 0.0, r = 1000000000.0;
        while (r - l > 1e-5) {
            double mid = (l + r) / 2.0;
            double under = check(mid, squares);

            if (under >= total / 2.0)
                r = mid;
            else
                l = mid;
        }
        return l;
    }
};
