// Last updated: 6/10/2026, 11:46:34 AM
class Solution
{
private:
// اللهم اهدنا يا رب اليك

public:
    int numberOfSubstrings(string s) {
        map<int,int> mp;
        long long n = s.size();
        long long ans = 0;
        for(int i = 0 , j = 0; i < n; i++){
            mp[s[i]]++;
            while(mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0){
                mp[s[j]]--;
                j++;
            }
            ans += i-j+1;
        }
        return n*(n+1)/2 - ans;
    }
};
//  n   n(n+1)/2 - ans