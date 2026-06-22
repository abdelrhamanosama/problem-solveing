// Last updated: 6/22/2026, 3:52:15 AM
1class Solution {
2public:
3    int rearrangeCharacters(string s, string target) {
4        map<char, int> mp;
5        map<char,int>freq;
6        string test = target;
7        for (auto x : test)
8            {
9                mp[x];
10                freq[x]++;
11            }
12        for (auto i : s) {
13            if (test.find(i) != string::npos) {
14                mp[i]++;
15            }
16        }
17
18        int mn = 1e9;
19        for (auto x : mp) {
20            
21                mn = min(mn, x.second/freq[x.first]);
22        }
23        return mn;
24    }
25};