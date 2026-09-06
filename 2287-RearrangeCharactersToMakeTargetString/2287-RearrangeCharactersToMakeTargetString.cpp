// Last updated: 9/6/2026, 2:18:35 PM
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        map<char, int> mp;
        map<char,int>freq;
        string test = target;
        for (auto x : test)
            {
                mp[x];
                freq[x]++;
            }
        for (auto i : s) {
            if (test.find(i) != string::npos) {
                mp[i]++;
            }
        }

        int mn = 1e9;
        for (auto x : mp) {
            
                mn = min(mn, x.second/freq[x.first]);
        }
        return mn;
    }
};