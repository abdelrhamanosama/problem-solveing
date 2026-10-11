// Last updated: 10/11/2026, 5:07:44 PM
1class Solution {
2public:
3    int minInsertions(string s) {
4        stack<char> st;
5        int n = s.size();
6        int sum = 0;
7        for (int i = 0; i < n; i++) {
8            if(s[i] == '(') st.push(s[i]);
9            else{
10                if(i+1 < n && s[i+1]  == ')'){
11                    i++;
12                }
13                else 
14                    sum++;
15                
16                if(st.empty()) sum++;
17                else st.pop();
18            }
19        }
20
21        return sum + st.size() *2;
22    }
23};