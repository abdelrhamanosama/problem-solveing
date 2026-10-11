// Last updated: 10/11/2026, 3:49:45 PM
1class Solution {
2public:
3    string removeOuterParentheses(string s) {
4        string res = "";
5        stack<char> st;
6        for(auto x: s){
7            if(st.empty()){
8                st.push(x);
9            }
10            else if(x == ')' && st.top() == '(') {
11                if(st.size() == 1){
12                    
13                }
14                else {
15                    res+=x;
16                }
17                    st.pop();
18
19            }
20            else {
21                res+=x;
22                st.push(x);
23
24            }
25        }
26        return res;
27    }
28};