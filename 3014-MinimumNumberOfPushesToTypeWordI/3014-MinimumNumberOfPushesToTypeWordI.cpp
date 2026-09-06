// Last updated: 9/6/2026, 2:16:30 PM
class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        if(n <= 8) return n;
        map<int,int>mp;
        for(auto x: word) mp[x-'a']++;
        vector<int> cnt;
        for(auto x:mp)
            cnt.push_back(x.second);
        sort(cnt.begin() , cnt.end());
        // cout<<cnt.size();
    
        int sum = 0 , i = 0;
        for(auto x:cnt){
            if(i < 8)
                sum+=x;
            else if(i < 16)
                sum+=(x*2);
            else if(i<24)
                sum+=(x*3);
            else 
                sum+=(x*4);
            i++;
            // cout<<x<<" ";
        }
        return sum;
    }
};