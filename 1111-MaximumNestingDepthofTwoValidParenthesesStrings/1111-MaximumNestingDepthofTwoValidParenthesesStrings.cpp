// Last updated: 9/30/2026, 2:33:41 PM
1class Solution {
2public:
3    vector<int> maxDepthAfterSplit(string seq) {
4       vector<int> pref;
5       stack<char> st;
6       int mx = 0;
7       for(int i = 0 ; i < seq.size(); i++){
8            if(st.empty()){
9                st.push('(');
10                pref.push_back(st.size());
11            }
12            else if(seq[i] == ')' && st.top() == '(') {
13                pref.push_back(st.size());
14                st.pop();
15            }
16            else 
17                {
18                    st.push('(');
19                    pref.push_back(st.size());   
20                }
21            mx = max(mx , (int)st.size());
22       }
23       int sz = 0;
24       if(mx & 1){
25        sz = mx/2 + 1;
26       } 
27       else 
28        sz = mx/2;
29        map<int,int> mp;
30        for(int i = 1; i<=sz; i++ ) mp[i] = 0;
31        for(int i = sz+1; i<=mx; i++ ) mp[i] = 1;
32        vector<int> ans;
33        for(auto x:pref){
34            ans.push_back(mp[x]);
35        }
36        return ans;
37    }
38};