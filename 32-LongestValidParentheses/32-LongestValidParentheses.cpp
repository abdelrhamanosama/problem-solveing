// Last updated: 10/4/2026, 1:21:53 AM
1class Solution {
2public:
3    int longestValidParentheses(string s) {
4        int res  = 0;
5        stack<int> st;
6        st.push(-1);
7        for(int i = 0 ; i < s.size(); i++){
8            if(s[i] == '(')
9            {
10                st.push(i);
11            }
12            else
13                {
14                    st.pop();
15                    if(st.empty())  
16                        st.push(i);
17                    else
18                        res = max(res , i-st.top());
19                }
20        }
21        return res;
22    }
23};