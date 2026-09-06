// Last updated: 9/6/2026, 2:13:33 PM
class Solution {
public:
    string processStr(string s) {
     string result = "";
     for(auto x:s){
      if(x  == '*'){
        if(result.size())
        result.pop_back();
      }
      else if(x == '#'){
        result = result + result;
      }
      else if(x == '%') {
        reverse(result.begin() , result.end());
      }
      else {
          result += x;
      }
     }   
     return result;
    }
};