// Last updated: 6/10/2026, 11:42:55 AM
class Solution {
public:
    int countOperations(int num1, int num2) {
        int cnt = 0;
        while(num1 && num2){
            if(num1 >= num2) num1-=num2;
            else num2-=num1;
            cnt++;
        }
        return cnt;
    }
};