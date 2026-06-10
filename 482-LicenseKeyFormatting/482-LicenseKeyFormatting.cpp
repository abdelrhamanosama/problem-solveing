// Last updated: 6/10/2026, 11:48:55 AM
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int cnt = 0;
        for(auto &x:s)
            if(x != '-')
                {
                    cnt++;
                    if(x > 'Z')
                        x -=('a'-'A'); 
                }
        string ans = "";
        cout<<cnt<<"\n";
        int i = 0 , times = 0 , j = 0;
        if(cnt%k != 0)
        {
            int t = 0;
            for( ; i < s.size() && t < cnt%k; i++)
                if(s[i] != '-')
                   {
                    ans += s[i];
                    t++;
                    j++;
                   }
            if(j < cnt)
            ans += "-";
        }
        for(; i < s.size(); i++){
            if(s[i] != '-')
                {
                    ans += s[i];
                    times++;
                    j++;
                }
            // cout<<ans<<"\t\t"<<i<<"\t\t"<<(times == k && ans.size() < cnt)<<"\n";
            if(times == k && j < cnt) 
                {
                    ans += "-";
                    times = 0;
                }
            // cout<<ans<<"\t\t"<<i<<"\t\t"<<(times == k && ans.size() < cnt)<<"\n";
        }
        return ans;
    }
};