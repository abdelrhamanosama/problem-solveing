// Last updated: 9/6/2026, 2:12:21 PM
class Solution {
public:
    int mirrorDistance(int n) {
        string s = to_string(n);
        reverse(s.begin() , s.end());
        int x = stoi(s);
        
        return abs(x-n);

    }
};