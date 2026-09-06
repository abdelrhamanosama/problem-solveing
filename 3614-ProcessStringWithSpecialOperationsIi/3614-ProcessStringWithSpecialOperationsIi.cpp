// Last updated: 9/6/2026, 2:13:26 PM
class Solution {
public:
    char processStr(string s, long long k) {

        long long len = 0;

        // Forward pass: compute final length only
        for (char c : s) {

            if (c == '*') {
                len = max(0LL, len - 1);
            }
            else if (c == '#') {
                len *= 2;
            }
            else if (c == '%') {
                continue;
            }
            else {
                len++;
            }
        }

        if (k >= len)
            return '.';

        // Backward pass
        for (int i = (int)s.size() - 1; i >= 0; i--) {

            char c = s[i];

            if (c == '#') {

                long long half = len / 2;

                if (k >= half)
                    k -= half;

                len = half;
            }

            else if (c == '%') {

                k = len - 1 - k;
            }

            else if (c == '*') {

                len++;
            }

            else {
                len--;
                if (k == len)
                    return c;
            }
        }

        return '.';
    }
};