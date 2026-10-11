// Last updated: 10/11/2026, 4:04:53 PM
1class Solution {
2public:
3    int minInsertions(string s) {
4        stack<char> st;
5        int ans = 0;
6
7        for (int i = 0; i < s.size(); i++) {
8            if (s[i] == '(') {
9                st.push('(');
10            } 
11            else {
12                // If this is not the second ')' of a pair,
13                // insert the missing ')'.
14                if (i + 1 < s.size() && s[i + 1] == ')') {
15                    i++;
16                } else {
17                    ans++;
18                }
19
20                // Match the pair of ')' with an opening '('.
21                if (!st.empty()) {
22                    st.pop();
23                } else {
24                    // Missing opening '('.
25                    ans++;
26                }
27            }
28        }
29
30        // Each remaining '(' needs two ')'.
31        ans += 2 * st.size();
32
33        return ans;
34    }
35};