// Last updated: 6/10/2026, 11:47:52 AM
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