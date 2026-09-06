// Last updated: 9/6/2026, 2:18:21 PM
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(auto s:queries){
            for(auto y:dictionary){
                int k = 0 , n = s.size();
                for(int i = 0 ; i < n; i++){
                    k += s[i] != y[i];
                }
                if(k<=2) {
                    ans.push_back(s);
                    break;
                }
            }
        }  
        return ans; 
    }
};