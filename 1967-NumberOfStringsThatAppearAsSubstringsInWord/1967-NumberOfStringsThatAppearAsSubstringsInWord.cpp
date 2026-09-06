// Last updated: 9/6/2026, 2:20:32 PM
class Solution {
public:
    
int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        for(auto x: patterns){
          if(word.find(x) != string::npos) cnt++;
        }
        return cnt;
    }
};