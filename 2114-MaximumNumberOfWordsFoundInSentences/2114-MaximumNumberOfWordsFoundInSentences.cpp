// Last updated: 9/6/2026, 2:19:27 PM
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