// Last updated: 6/17/2026, 4:32:47 PM
1class Solution {
2public:
3    char processStr(string s, long long k) {
4
5        long long len = 0;
6
7        // Forward pass: compute final length only
8        for (char c : s) {
9
10            if (c == '*') {
11                len = max(0LL, len - 1);
12            }
13            else if (c == '#') {
14                len *= 2;
15            }
16            else if (c == '%') {
17                continue;
18            }
19            else {
20                len++;
21            }
22        }
23
24        if (k >= len)
25            return '.';
26
27        // Backward pass
28        for (int i = (int)s.size() - 1; i >= 0; i--) {
29
30            char c = s[i];
31
32            if (c == '#') {
33
34                long long half = len / 2;
35
36                if (k >= half)
37                    k -= half;
38
39                len = half;
40            }
41
42            else if (c == '%') {
43
44                k = len - 1 - k;
45            }
46
47            else if (c == '*') {
48
49                len++;
50            }
51
52            else {
53                len--;
54                if (k == len)
55                    return c;
56            }
57        }
58
59        return '.';
60    }
61};