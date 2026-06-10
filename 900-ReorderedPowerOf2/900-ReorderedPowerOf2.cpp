// Last updated: 6/10/2026, 11:47:40 AM
#define sz(s) (int)(s).size()

class Solution {
public:
    bool found = 0;
    
    void backtrack(int i , vector<int>& d, int num, int cnt, vector<bool>& vis){
        if(cnt == sz(d)){
            if((num & (num - 1)) == 0) // check power of 2
                found = 1;
            return;
        }
        for(int j = 0 ; j < sz(d); j++){
            if(vis[j]) continue;
            if(cnt == 0 && d[j] == 0) continue; // skip leading zero
            
            vis[j] = 1;
            backtrack(0, d, num * 10 + d[j], cnt + 1, vis);
            vis[j] = 0;
        }
    }

    bool reorderedPowerOf2(int n) {
        vector<int> digits;
        while(n){
            digits.push_back(n % 10);
            n /= 10;
        }
        vector<bool> vis(sz(digits), 0);
        backtrack(0, digits, 0, 0, vis);
        return found;
    }
};
