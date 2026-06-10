// Last updated: 6/10/2026, 11:42:54 AM
class Solution {
public:
    int countCollisions(string s) {

        int cnt = 0;
        int flag = -1;
        for (int i = 0; i < s.size(); i++) {
            if(s[i] == 'L'){
                if(flag >= 0)
                    {
                        cnt += flag + 1;
                        flag = 0;
                    }
            }    
            else if(s[i] == 'S'){
                if(flag > 0)
                    cnt += flag;
                flag = 0;
            }
            else {
                if(flag >= 0)
                    flag ++;
                else 
                    flag = 1;
            }
        
        }
        cout << cnt;
        return cnt;
    }
};