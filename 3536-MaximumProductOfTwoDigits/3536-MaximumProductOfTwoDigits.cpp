// Last updated: 9/6/2026, 2:14:06 PM
class Solution {
public:
    int maxProduct(int n) {
        int mx1 , mx2;
        mx1 = mx2 = 0;
        while(n){
            int d = n%10;
            if(d >= mx1){
                mx2 = mx1;
                mx1 = d ;
            }
            else if(d > mx2) 
                mx2 = d;
            n/=10;
        }
        return mx1*mx2;
    }
};