// Last updated: 9/6/2026, 4:00:42 PM
class Solution {
#define sz(s) (int)(s).size()
#define all(s) s.begin(),s.end()
public:vector<int> beautifulArray(int n) {
    vector<int> ans;
    ans.push_back(1);
    while(ans.size() < n){
        vector<int> temp;
        for(auto x: ans){
            if(2*x - 1 <= n) 
                temp.push_back(2*x-1);
        }
        for(auto x: ans){
            if(2*x  <= n) 
                temp.push_back(2*x);
        }
        ans = temp;
    }
    return ans;
}

};