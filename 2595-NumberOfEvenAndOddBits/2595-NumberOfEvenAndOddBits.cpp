// Last updated: 9/6/2026, 2:17:50 PM
class Solution {
public:
    vector<int> evenOddBit(int n) {
       int odd = 0;
       int even = 0;
       int i = 0;
        while(n){
            int d = n&1;
            if(i&1) odd +=  d;
            else even +=d;
            n>>=1;
            i++;
        } 
        return {even , odd};
    }
};