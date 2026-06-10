// Last updated: 6/10/2026, 11:48:23 AM
class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long a = 0; a * a <= c; a++){
            long long b = sqrt(c - a * a);
            if(a * a + b * b == c) return true;
        }
        return false;
    }
};