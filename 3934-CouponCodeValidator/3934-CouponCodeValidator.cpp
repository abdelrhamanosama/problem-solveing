// Last updated: 6/10/2026, 11:41:23 AM
class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        vector<pair<string, string>> v;
        for (int i = 0; i < businessLine.size(); i++) {
            bool validCode = code[i].size() > 0;
            for (char c : code[i]) {
                if (!((c >= 'a' && c <= 'z') ||
                      (c >= 'A' && c <= 'Z') ||
                      (c >= '0' && c <= '9') ||
                      c == '_')) {
                    validCode = false;
                    break;
                }
            }

            // check valid businessLine
            if (!(businessLine[i] == "electronics" ||
                  businessLine[i] == "grocery" ||
                  businessLine[i] == "pharmacy" ||
                  businessLine[i] == "restaurant"))
                continue;

            if (isActive[i] && validCode)
                v.push_back({businessLine[i], code[i]});
        }

        sort(v.begin(), v.end());
        vector<string> result;
        for (auto x : v)
            result.push_back(x.second);

        return result;
    }
};
