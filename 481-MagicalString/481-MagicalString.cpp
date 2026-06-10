// Last updated: 6/10/2026, 11:48:56 AM
class Solution {
#define all(s) s.begin(),s.end()

public:
    int magicalString(int n) {
        if (n <= 3)
            return 1;
        vector<int> v = {1, 2, 2};
        int i = 2, val = 1;
        while (v.size() < n) {
            if (val == 1) {
                
                v.push_back(val);
                if (v.at(i) == 2) {
                    v.push_back(val);
                    // i++;
                }
                i++;
                val = 2;
            } else {
                v.push_back(val);
                if (v.at(i) == 2) {
                    v.push_back(val);
                // i++;
                }
                i++;
                val = 1;
            }
        }
        // for(auto x : v) cout<<x<<" ";
        return count(v.begin() , v.begin() + n, 1);
    }
};