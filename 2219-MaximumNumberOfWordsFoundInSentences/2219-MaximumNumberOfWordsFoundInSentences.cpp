// Last updated: 6/10/2026, 11:43:17 AM
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
       int ans = 0;
       for(auto x : sentences){
            int cnt = 0;
            for(auto y:x)
                cnt += y == ' ';
            ans = max(ans , cnt+1);
       } 
       return ans;
    }
};