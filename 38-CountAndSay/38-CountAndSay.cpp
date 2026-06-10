// Last updated: 6/10/2026, 11:51:00 AM
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string s = "1";
        for (int i = 2; i <= n; ++i) {
            string temp = "";
            int cnt = 1;
            for (int j = 1; j < s.length(); ++j) {
                if (s[j] == s[j - 1]) {
                    ++cnt;
                } else {
                    temp += to_string(cnt) + s[j - 1];
                    cnt = 1;
                }
            }
            temp += to_string(cnt) + s.back();
            s = temp;
        }
        return s;
    }
};