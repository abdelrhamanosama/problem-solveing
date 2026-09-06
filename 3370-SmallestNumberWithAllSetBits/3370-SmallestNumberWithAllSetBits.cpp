// Last updated: 9/6/2026, 2:15:01 PM
class Solution {
public:
    int smallestNumber(int n) {
        int len = 0;
        int temp = n;
        int cnt = 0;
        while(n) {
            if(n&1) cnt++;
            n/=2;
            len++;
        }
        // if(cnt == len) 
        //     return (1<<(len)) -1;
        // else
            return (1<<(len)) -1;

    }
};