// Last updated: 6/10/2026, 11:49:30 AM
class Solution {
    #define all(s) s.begin(), s.end()

public:
    bool isAnagram(string s, string t) {
          sort(all(s)); 
          sort(all(t));
        return s == t;
    }
};