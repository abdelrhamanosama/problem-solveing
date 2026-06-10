// Last updated: 6/10/2026, 11:47:11 AM
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>,int>mp;
        int mx = 0;
        for(int i = 0 ; i < dominoes.size(); i++)      {
            int a = dominoes[i][0];
            int b = dominoes[i][1];
            if(a<b){
                mp[{a,b}]++;
            }
            else
                mp[{b,a}]++;
        }
    
        for(auto i :mp)
            {
                mx += (i.second)*(i.second-1)/2;
            }
        return mx;
    }
};