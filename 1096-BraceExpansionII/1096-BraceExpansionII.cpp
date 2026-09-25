// Last updated: 9/25/2026, 9:41:33 AM
1
2class Solution {
3    string s;
4    int pos;
5
6    set<string> concat(const set<string>& A,
7                       const set<string>& B) {
8
9        set<string> res;
10
11        for (const string& a : A) {
12            for (const string& b : B) {
13                res.insert(a + b);
14            }
15        }
16
17        return res;
18    }
19
20    set<string> parseFactor() {
21
22        if (s[pos] == '{') {
23            pos++; // {
24
25            set<string> res = parseExpression();
26
27            pos++; // }
28
29            return res;
30        }
31
32        return {string(1, s[pos++])};
33    }
34
35    set<string> parseTerm() {
36
37        set<string> res = {""};
38
39        while (pos < s.size() &&
40               s[pos] != ',' &&
41               s[pos] != '}') {
42
43            set<string> cur = parseFactor();
44
45            res = concat(res, cur);
46        }
47
48        return res;
49    }
50
51    set<string> parseExpression() {
52
53        set<string> res = parseTerm();
54
55        while (pos < s.size() && s[pos] == ',') {
56
57            pos++; // ,
58
59            set<string> cur = parseTerm();
60
61            res.insert(cur.begin(), cur.end());
62        }
63
64        return res;
65    }
66
67public:
68    vector<string> braceExpansionII(string expression) {
69
70        s = expression;
71        pos = 0;
72
73        set<string> res = parseExpression();
74
75        return vector<string>(res.begin(), res.end());
76    }
77};
78