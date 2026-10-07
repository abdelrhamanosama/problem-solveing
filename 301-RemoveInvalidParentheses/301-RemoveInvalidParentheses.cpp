// Last updated: 10/8/2026, 12:21:15 AM
1class Solution {
2    set<string> ans;
3
4    void backtrack(string& s, int pos,
5                   int leftRem, int rightRem,
6                   int balance, string& cur) {
7
8        if (pos == s.size()) {
9            if (leftRem == 0 &&
10                rightRem == 0 &&
11                balance == 0) {
12                ans.insert(cur);
13            }
14
15            return;
16        }
17
18        char c = s[pos];
19
20        // Letter
21        if (c != '(' && c != ')') {
22            cur += c;
23            backtrack(s, pos + 1, leftRem, rightRem, balance, cur);
24            cur.pop_back();
25            return;
26        }
27
28        // Remove current parenthesis
29        if (c == '(' && leftRem > 0) {
30            backtrack(s, pos + 1,
31                      leftRem - 1,
32                      rightRem,
33                      balance,
34                      cur);
35        }
36
37        if (c == ')' && rightRem > 0) {
38            backtrack(s, pos + 1,
39                      leftRem,
40                      rightRem - 1,
41                      balance,
42                      cur);
43        }
44
45        // Keep current parenthesis
46        if (c == '(') {
47            cur += c;
48
49            backtrack(s, pos + 1,
50                      leftRem,
51                      rightRem,
52                      balance + 1,
53                      cur);
54
55            cur.pop_back();
56        }
57        else {
58            if (balance > 0) {
59                cur += c;
60
61                backtrack(s, pos + 1,
62                          leftRem,
63                          rightRem,
64                          balance - 1,
65                          cur);
66
67                cur.pop_back();
68            }
69        }
70    }
71
72public:
73    vector<string> removeInvalidParentheses(string s) {
74
75        int leftRem = 0;
76        int rightRem = 0;
77
78        for (char c : s) {
79
80            if (c == '(') {
81                leftRem++;
82            }
83            else if (c == ')') {
84
85                if (leftRem > 0)
86                    leftRem--;
87                else
88                    rightRem++;
89            }
90        }
91
92        string cur;
93
94        backtrack(s, 0,
95                  leftRem,
96                  rightRem,
97                  0,
98                  cur);
99
100        return vector<string>(ans.begin(), ans.end());
101    }
102};