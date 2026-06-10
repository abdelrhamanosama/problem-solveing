// Last updated: 6/10/2026, 11:41:31 AM
class Solution {
#define ll long long

public:
    int countPermutations(vector<int>& complexity) {
    int n = complexity.size();
    int f = 0;
    for(int i = 0 ; i <n; i++){
        f |= complexity[i]<=complexity[0] && i>0;
    }
    if(f) return 0;
    int mod = 1e9 + 7;
    ll prod = 1;
    for(ll i = n-1; i >= 1; i--){
        prod = (prod*i)%mod;
        prod%=mod;
    }
    return prod;
    }
};