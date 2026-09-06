// Last updated: 9/6/2026, 4:01:23 PM
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int>mp;
        int cnt = 0;
        for(int i = 0 ; i < answers.size(); i++)    
            mp[answers[i]]++;
        int ans = 0;
        for(auto it : mp)
                ans += ceil(it.second/((it.first+1)*1.0))*((it.first+1));
        return ans;
    }
};