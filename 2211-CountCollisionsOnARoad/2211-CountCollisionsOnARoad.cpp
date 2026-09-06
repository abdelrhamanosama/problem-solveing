// Last updated: 9/6/2026, 2:18:49 PM
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