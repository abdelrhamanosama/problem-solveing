// Last updated: 6/10/2026, 11:45:28 AM
class Solution {
public:
    int minimumOneBitOperations(int n) {
        return dp(n);
    }
    int dp(int n){
        long long ans = 0;
        long long  i = 0;
        int mask = 1;
        while(mask <= n){
            if(mask & n){
                ans = (1 << (i+1)) -1 - ans;
            }
            mask *= 2;
            i++;
        }
        return ans;
    }


};
/*
1  ==> base case return 1
2  ==> state 1 + 2
3  ==> state 1 + 1
4  ==> state 2 + 1
5  ==> state 4 + 1
6  ==> state 2 + 1
7  ==> state 6 + 1
8  ==> state 4 + 1
9  ==> state 8 + 1
10 ==> state 8 + 2
11 ==> state 8 + 3
12 ==> state 4 + 1

*/