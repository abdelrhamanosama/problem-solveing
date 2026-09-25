// Last updated: 9/25/2026, 9:57:34 AM
1/* صلِّ على النبي */
2#include <bits/stdc++.h>
3
4#include <ext/pb_ds/assoc_container.hpp>
5using namespace __gnu_pbds;
6using namespace std;
7#define ll long long
8#define sz(s) (int)(s).size()
9#define all(s) s.begin(), s.end()
10
11
12class Solution {
13public:
14    int pos ;
15    set<string> concate(set<string> a, set<string> b){
16        // cartesien product
17        set<string> s;
18        for(auto x:a)
19            for(auto y:b)
20                s.insert(x+y);
21        return s;
22    }
23
24    set<string> ParseFactor(string s){
25        set<string> res;
26        if(s[pos] == '{'){
27            pos++; // handle starting { 
28            res = ParseExpr(s); // just handle  , don't care curly beraces
29            pos++; // handle ending }
30        }
31        else 
32            res.insert(string(1, s[pos++]));
33        return res;
34    }
35    set<string> ParseTerm(string s){
36        set<string> res = {""};
37
38        while(pos < s.size() 
39        && s[pos] != ','  // go to expression to handle next unoin expression
40        && s[pos] !='}' // end orginal expresion
41        ){
42            set<string> cur = ParseFactor(s);
43            res = concate(res , cur);
44        }
45        return res;
46    }
47    set<string> ParseExpr(string s){
48        set<string> res = ParseTerm(s);
49        while(pos < s.size() && s[pos] == ','){
50            pos++;
51            set<string> cur = ParseTerm(s);
52            res.insert(all(cur));
53        }
54
55        return res;
56    }
57
58    vector<string> braceExpansionII(string expression) {
59        pos = 0;
60        set<string> s = ParseExpr(expression);
61
62        return vector<string>(all(s));
63    }
64};