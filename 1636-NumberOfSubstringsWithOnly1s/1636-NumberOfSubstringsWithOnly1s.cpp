// Last updated: 6/10/2026, 11:45:41 AM
class Solution {
public:
    int mod = 1e9 + 7;
    int numSub(string s) {
        return rle(s);
    }
    int rle( string s) {
    long long ans = 0;
    long long count = 1;
    for (int i = 1; i < (int)s.size(); i++) {
        if (s[i] == s[i - 1]) {
            count++;
        } else {
            if(s[i-1] == '1')
                ans += (count * (count + 1)/2)%mod;
            ans %= mod; 
            count = 1;
        }
    }
    if(s.back() == '1') 
    ans += (count * (count + 1)/2)%mod;
    ans %= mod; 
    return ans;
}
};