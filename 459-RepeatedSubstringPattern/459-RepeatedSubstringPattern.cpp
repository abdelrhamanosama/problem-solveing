// Last updated: 6/10/2026, 11:48:59 AM
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i = 1 ; i < s.size(); i++){
            if(s.size() % i != 0) continue;
            string x = "" ,y = "";
            bool  firstTime = 1 , breaked = 0;
            for(int j = 0 , last = 0;j < s.size(); j++){
                x += s[j];
                if(j+1 - last == i && firstTime){
                    last = j+1;
                    y = x;
                    x = "";
                    firstTime = 0;
                }
                else if(j+1 - last == i && !firstTime){
                    if(y != x) {
                        breaked = 1;
                        break;
                    }
                    last = j+1;
                    x = "";
                }
            }
            if(y != x && x != "" ) breaked = 1;
            if(!breaked) {
                return 1;
            }
        }
        return 0;
    }
};