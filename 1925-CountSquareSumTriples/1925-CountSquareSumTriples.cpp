// Last updated: 9/6/2026, 2:20:53 PM
class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        for(int i = 1 ; i <= n; i++)
            for(int j = 1; j <=n; j++ ){
                    int ans = i*i + j *j;
                    if((sqrt(ans) - (int)sqrt(ans) == 0) && sqrt(ans) <= n) cnt++;
            }
        return cnt;
    }
};