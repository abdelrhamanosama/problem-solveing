// Last updated: 6/10/2026, 11:43:09 AM
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans=0, prev=-1;
        for(auto x: bank){
            int cnt = 0;
            for(auto y : x){
                if(y - '0')
                    cnt++;
            }
            if(prev == -1){
                prev = cnt;
                continue;
            }
            else if(cnt){
                ans += cnt *prev;
                prev = cnt;
            }
        }
        return ans;
    }
};