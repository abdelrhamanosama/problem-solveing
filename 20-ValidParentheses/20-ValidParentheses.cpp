// Last updated: 9/25/2026, 7:48:31 AM
1class Solution {
2public:
3    string removeDuplicates(string s, int k) {
4        stack<pair<char, int>> st;
5
6        for (char c : s) {
7            if (!st.empty() && st.top().first == c) {
8                st.top().second++;
9
10                if (st.top().second == k) {
11                    st.pop();
12                }
13            }
14            else {
15                st.push({c, 1});
16            }
17        }
18
19        string ans;
20
21        while (!st.empty()) {
22            auto [c, cnt] = st.top();
23            st.pop();
24
25            while (cnt--) {
26                ans += c;
27            }
28        }
29
30        reverse(ans.begin(), ans.end());
31
32        return ans;
33    }
34};