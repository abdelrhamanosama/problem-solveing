// Last updated: 9/6/2026, 2:15:56 PM
/* صلِّ على النبي */
#include <bits/stdc++.h>
using namespace std;
// #define int long long
// #define sz(s) (int)(s).size()
#define all(s) s.begin(), s.end()

class Solution
{
private:
    // اللهم اهدنا يا رب اليك
public:
    int numberOfSpecialChars(string word) {
        set<int> s,S;
        int freq[26] = { };
        int cnt = 0;
        for(auto x:word){
            if(x >= 'a' && S.find(x-('a'-'A'))!=S.end())
                {
                    freq[x-'a']++;
                    s.insert(x);
                    continue;
                }
            
            if(x < 'a' && s.find(x+('a'-'A'))!=s.end()){
                    freq[x-'A']++;
                S.insert(x);
            }
            if(x>='a') s.insert(x);
            else S.insert(x); 
        }
        for(int i = 0 ; i <26 ; i++) cnt+=(freq[i] > 0); 
        return cnt;
    }
};
