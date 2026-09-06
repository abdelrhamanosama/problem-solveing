// Last updated: 9/6/2026, 2:25:18 PM
/* صلِّ على النبي */
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define sz(s) (int)(s).size()
#define all(s) s.begin(), s.end()

class Solution
{

private:

struct DoubleHash {

    // using ll = long long;

    static const int MOD1 = 1000000007;
    static const int MOD2 = 1000000009;

    static const int BASE1 = 911382323;
    static const int BASE2 = 972663749;

    vector<ll> h1, h2;
    vector<ll> p1, p2;
    int n;
    DoubleHash(const string &s) {

        n = s.size();

        h1.assign(n + 1, 0);
        h2.assign(n + 1, 0);

        p1.assign(n + 1, 1);
        p2.assign(n + 1, 1);

        for (int i = 1; i <= n; i++) {

            p1[i] = (p1[i - 1] * BASE1) % MOD1;
            p2[i] = (p2[i - 1] * BASE2) % MOD2;

            h1[i] = (h1[i - 1] * BASE1 + s[i - 1]) % MOD1;
            h2[i] = (h2[i - 1] * BASE2 + s[i - 1]) % MOD2;
        }
    }

    pair<ll,ll> get_hash(int l, int r) {

        ll x1 = (h1[r + 1] -
                 h1[l] * p1[r - l + 1]) % MOD1;

        if (x1 < 0)
            x1 += MOD1;

        ll x2 = (h2[r + 1] -
                 h2[l] * p2[r - l + 1]) % MOD2;

        if (x2 < 0)
            x2 += MOD2;

        return {x1, x2};
    }

    bool equal(int l1,int r1,int l2,int r2){

        return get_hash(l1,r1) == get_hash(l2,r2);
    }

};

bool isPalindrome(int l,int r,DoubleHash &H,DoubleHash &RH){
 
    auto a = H.get_hash(l,r);
 
    int n = H.n;
 
    int rl = n-1-r;
    int rr = n-1-l;
 
    auto b = RH.get_hash(rl,rr);
 
    return a==b;
}
public:
    string longestPrefix(string s) {
        DoubleHash h(s);
        int ans = -1;
        
        for(int i = 0 , j = s.size() - 1 ; i < s.size()-1; i++,j--){
            if(h.equal(0,i,j,s.size()-1)){
                ans = i;
            }
        }
        
        return s.substr(0,ans+1);
    }
};