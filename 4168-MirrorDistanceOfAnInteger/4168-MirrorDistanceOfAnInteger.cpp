// Last updated: 6/10/2026, 11:41:12 AM
class Solution {
public:
    int mirrorDistance(int n) {
        string s = to_string(n);
        reverse(s.begin() , s.end());
        int x = stoi(s);
        
        return abs(x-n);

    }
};