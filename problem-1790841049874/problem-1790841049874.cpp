// Last updated: 10/1/2026, 10:50:49 AM
1class Solution {
2public:
3    string minRemoveToMakeValid(string s) {
4       stack<pair<char,int>> st;
5        for(int i = 0 ; i < s.size(); i++){
6            if(st.empty() && (s[i] == '(' || s[i] == ')')) 
7                st.push({s[i] , i});
8            else if(s[i] == ')' && st.top().first == '(') 
9                st.pop();
10            else if(s[i] == '(' || s[i] == ')') 
11                st.push({s[i] , i});
12        }
13        set<int> ss;
14        while(!st.empty()){
15            ss.insert(st.top().second);
16            st.pop();
17        }
18        string res = "";
19        for(int i = 0 ; i < s.size(); i++){
20            if(ss.find(i) == ss.end()) res+=s[i];
21        }
22        return res;
23    }
24};