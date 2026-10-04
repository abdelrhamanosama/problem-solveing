// Last updated: 10/4/2026, 2:29:13 PM
1class Solution {
2public:
3    bool checkValidString(string s) {
4        set<int> stars;
5        stack<pair<char, int>> st;
6
7        for (int i = 0; i < s.size(); i++) {
8            if (s[i] == '*') {
9                stars.insert(i);
10            }
11            else {
12                if (st.empty()) {
13                    st.push({s[i], i});
14                }
15                else if (s[i] == ')' && st.top().first == '(') {
16                    st.pop();
17                }
18                else {
19                    st.push({s[i], i});
20                }
21            }
22        }
23
24        if (st.empty())
25            return true;
26
27        vector<pair<char, int>> parenthesis;
28
29        while (!st.empty()) {
30            parenthesis.push_back(st.top());
31            st.pop();
32        }
33
34        while (!parenthesis.empty()) {
35            auto [ch, pos] = parenthesis.back();
36            parenthesis.pop_back();
37
38            if (ch == '(') {
39                // Need a star AFTER this '('
40                auto it = stars.upper_bound(pos);
41
42                if (it == stars.end())
43                    return false;
44
45                stars.erase(it);
46            }
47            else {
48                // Need a star BEFORE this ')'
49                auto it = stars.lower_bound(pos);
50
51                if (it == stars.begin())
52                    return false;
53
54                --it;
55                stars.erase(it);
56            }
57        }
58
59        return true;
60    }
61};