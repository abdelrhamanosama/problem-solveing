// Last updated: 6/10/2026, 11:47:45 AM
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s == goal) return 1;
        for(int i  = 0 ; i < s.size(); i++){
            string try1 = makesShifting(i,s);
            if(try1 == goal) return 1;
        }
        return 0;
    }
    string makesShifting(int i  , string s){
       string s1 =  s.substr(0, i);
       string s2 =  s.substr(i);
       return s2 + s1;
    }
};