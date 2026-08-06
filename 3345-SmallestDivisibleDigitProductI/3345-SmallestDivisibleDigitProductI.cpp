// Last updated: 8/6/2026, 7:02:22 PM
1class Solution {
2public:
3    int smallestNumber(int n, int t) {
4        auto check = [&](int num) -> bool {
5            int product = 1;
6            while (num) {
7                product *= (num % 10);
8                num /= 10;
9                if (!product) {
10                    break;
11                }
12            }
13            return !(product % t);
14        };
15        while (!check(n)) {
16            n++;
17        }
18        return n;
19    }
20};