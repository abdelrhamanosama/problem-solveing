// Last updated: 7/19/2026, 3:23:21 PM
1class Solution {
2#define all(s) s.begin(), s.end()
3
4public:
5    string smallestSubsequence(string s) {
6
7        vector<int> freq(26, 0);
8        for (char c : s) freq[c - 'a']++;
9
10        stack<char> st;
11        vector<bool> vis(26, false);
12
13        for (char x : s) {
14
15            freq[x - 'a']--;
16
17            if (vis[x - 'a']) continue;
18
19            while (!st.empty() &&
20                   st.top() > x &&
21                   freq[st.top() - 'a'] > 0) {
22
23                vis[st.top() - 'a'] = false;
24                st.pop();
25            }
26
27            st.push(x);
28            vis[x - 'a'] = true;
29        }
30
31        string ans;
32
33        while (!st.empty()) {
34            ans += st.top();
35            st.pop();
36        }
37
38        reverse(all(ans));
39
40        return ans;
41    }
42};