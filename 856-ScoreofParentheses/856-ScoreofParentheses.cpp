// Last updated: 10/5/2026, 6:10:23 PM
1class Solution {
2public:
3    int scoreOfParentheses(string s) {
4        stack<int> st;
5
6        for (char c : s) {
7            if (c == '(') {
8                st.push(-1);
9            }
10            else {
11                int sum = 0;
12
13                while (st.top() != -1) {
14                    sum += st.top();
15                    st.pop();
16                }
17
18                st.pop(); // remove '('
19
20                st.push(sum == 0 ? 1 : 2 * sum);
21            }
22        }
23
24        int ans = 0;
25
26        while (!st.empty()) {
27            ans += st.top();
28            st.pop();
29        }
30
31        return ans;
32    }
33};