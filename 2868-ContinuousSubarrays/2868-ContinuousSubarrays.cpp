// Last updated: 6/10/2026, 11:42:22 AM
class Solution {
public:
    long long continuousSubarrays(vector<int>& a) {
    map<int,int>mp;
    int i = 0, j = 0;
    long long count = 0;
    for(;i < a.size();i++){
        mp[a[i]]++;
        while(abs(mp.rbegin()->first - mp.begin()->first) > 2 && j < i) // the biggest - the smallest
        {
            mp[a[j]]--;
            if(!mp[a[j]])
                mp.erase(a[j]);
            j++;
        }
        count += i  - j + 1;
    }
    return count;
}
};
auto speed = [](){cin.tie(0)->sync_with_stdio(0);return true;}();