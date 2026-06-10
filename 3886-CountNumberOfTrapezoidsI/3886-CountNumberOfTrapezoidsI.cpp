// Last updated: 6/10/2026, 11:41:28 AM
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        map<int,int> mp;
        for(auto x: points){
            mp[x[1]] ++;
        }
        unsigned long long ans = 0 , mod = 1e9 + 7, res = 0;
        for(auto x: mp){
            long long cnt = x.second;
            if(cnt > 1)
                ans += cnt * (cnt - 1) /2;
        }
        cout<<ans<<"\n";
        for(auto x: mp){
            long long cnt = x.second;
            if(cnt  > 1){
                ans -= cnt * (cnt - 1) /2;
                res += (ans * (cnt*(cnt -1)/2)%mod)%mod;
                res%=mod;
            }
        }
        return res%mod;

    }
};