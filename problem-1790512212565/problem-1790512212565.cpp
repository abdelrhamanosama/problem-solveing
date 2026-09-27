// Last updated: 9/27/2026, 3:30:12 PM
1class Solution {
2public:
3    string reverseParentheses(string s) {
4        stack<char> st;
5
6        for (int i = 0; i < s.size(); i++) {
7
8            if (s[i] == ')') {
9
10                string rev = "";
11
12                while (st.top() != '(') {
13                    rev += st.top();
14                    st.pop();
15                }
16
17                st.pop(); // remove '('
18
19                for (auto x : rev)
20                    st.push(x);
21            }
22            else {
23                st.push(s[i]);
24            }
25        }
26
27        string ans = "";
28
29        while (!st.empty()) {
30            ans += st.top();
31            st.pop();
32        }
33
34        reverse(ans.begin(), ans.end());
35
36        return ans;
37    }
38};