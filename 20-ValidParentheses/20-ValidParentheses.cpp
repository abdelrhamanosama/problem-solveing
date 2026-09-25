// Last updated: 9/25/2026, 7:25:22 AM
1class Solution {
2public:
3    bool isValid(string s) {
4       stack<char> st;
5        for(int i = 0 ; i< s.size();i ++){
6            if(st.empty()) st.push(s[i]);
7            else if(st.top() == '(' && s[i] == ')' || st.top() == '[' && s[i] == ']' || st.top() == '{' && s[i] == '}' ) st.pop();
8
9            else  st.push(s[i]);
10        } 
11        return st.size() == 0;
12    }
13};