// Last updated: 9/6/2026, 2:15:44 PM
class Solution {
public:
    int maxOperations(string s) {
    int i = 0; 
    int ans = 0;
    int n = s.size();
    int ones = 0;
    bool moved = 0;
    for(; i < n ; i++){
        if(s[i] == '1'){
            ones++;
            moved = 1;
            continue;
        }
        if(moved){
            int z = 0;
            for(int j = i;j < n; j++)
                if( s[j] == '1') break;
                else z++;
            moved = 0;
            ans += ones;
        }
    }
    return ans++;
}
};