// Last updated: 6/10/2026, 11:47:43 AM
class Solution {
public:
    string maskPII(string s) {
        // Email
        if(s.find("@") != string::npos){
            int idx = s.find("@");
            string sub = "";
            
            // first character in lowercase
            sub += tolower(s[0]);
            sub += "*****";
            sub += tolower(s[idx-1]);

            // add domain in lowercase
            for(int i = idx; i < s.size(); i++)
                sub += tolower(s[i]);
            
            return sub;
        }

        // Phone number
        int cnt = 0, last = 0;
        string last4 = "";

        // count digits + capture last 4
        for(int i = s.size()-1; i >= 0; i--){
            if(isdigit(s[i])){
                cnt++;
                if(last < 4){
                    last4 += s[i];
                    last++;
                }
            }
        }

        reverse(last4.begin(), last4.end());
        
        // build return string
        string res = "";
        int extra = cnt - 10;   // country code digits

        if(extra > 0){
            res += "+";
            for(int i = 0; i < extra; i++)
                res += "*";
            res += "-";
        }

        res += "***-***-" + last4;
        return res;
    }
};
