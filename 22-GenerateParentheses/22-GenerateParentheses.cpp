// Last updated: 10/2/2026, 4:07:41 PM
1class Solution
2{
3private:
4
5    void backtrack(int n, string &s , vector<string> &v , int open , int close){
6        if(open  == n && close == n){
7                v.push_back(s);
8            return;
9        }
10        if(open < n)
11            {
12                s+='(';
13            backtrack(n, s ,v , open + 1 ,close);
14            s.pop_back();
15            }
16        if(close < open)
17            {
18                s+=')';
19            backtrack(n, s ,v, open ,close+ 1);
20            s.pop_back();
21            }
22    }
23
24public:
25    vector<string> generateParenthesis(int n) {
26        vector<string> v;
27        string s;
28        backtrack(n,s,v,0,0);
29        // vector<string> x;
30        // for(auto y:v) x.push_back(y);
31        return v;       
32    }
33};