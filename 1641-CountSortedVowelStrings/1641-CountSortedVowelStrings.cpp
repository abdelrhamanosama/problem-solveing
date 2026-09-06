// Last updated: 9/6/2026, 2:22:24 PM
class Solution {
public:
    string s = "aeiou";
    int mem[51][6];
    int countVowelStrings(int n) {
        memset(mem , -1 , sizeof mem);
        return dp(0,0,n);
    }
    int dp(int i , int j , int n){
    if(i>=n) return 1;
    if(~mem[i][j]) return mem[i][j];
    int opt = 0;
    for(int k = j ; j < s.size() ; j++)
        opt += dp(i+1 , j ,  n);
    return mem[i][j] = opt;
    }
};