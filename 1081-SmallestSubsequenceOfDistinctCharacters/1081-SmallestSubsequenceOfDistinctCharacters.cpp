// Last updated: 9/6/2026, 4:00:03 PM
class Solution {
#define all(s) s.begin(), s.end()

public:
    string smallestSubsequence(string s) {

        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        stack<char> st;
        vector<bool> vis(26, false);

        for (char x : s) {

            freq[x - 'a']--;

            if (vis[x - 'a']) continue;

            while (!st.empty() &&
                   st.top() > x &&
                   freq[st.top() - 'a'] > 0) {

                vis[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(x);
            vis[x - 'a'] = true;
        }

        string ans;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(all(ans));

        return ans;
    }
};