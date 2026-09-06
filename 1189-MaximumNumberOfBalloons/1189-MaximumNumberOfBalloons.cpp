// Last updated: 9/6/2026, 3:59:09 PM
class Solution {
public:
    int maxNumberOfBalloons(string text) {
          map<char,int> mp;
          string test = "balloon";
          for(auto x:test) mp[x];
          for(auto i :text) {
            if(test.find(i) != string::npos) {
              mp[i]++;
            }
          }
        int mn = 1e9;
        for(auto x:mp){
          if(x.first == 'o' || x.first == 'l') mn = min(mn , x.second/2);
          else mn = min(mn , x.second);
        }
        return mn;
    }
};