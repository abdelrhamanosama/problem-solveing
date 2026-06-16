// Last updated: 6/16/2026, 4:15:15 PM
1class Solution {
2public:
3    string processStr(string s) {
4     string result = "";
5     for(auto x:s){
6      if(x  == '*'){
7        if(result.size())
8        result.pop_back();
9      }
10      else if(x == '#'){
11        result = result + result;
12      }
13      else if(x == '%') {
14        reverse(result.begin() , result.end());
15      }
16      else {
17          result += x;
18      }
19     }   
20     return result;
21    }
22};