// Last updated: 6/10/2026, 11:43:39 AM
#pragma GCC optimize("Ofast","inline","fast-math","unroll-loops","no-stack-protector","-ffast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string ,int> mp;
        unordered_map<string ,int> mp2;
        vector<int>v;
        string s = arr[0];
        mp[s] = 0;  
        mp2[s]++; 
        for (int i = 1; i < arr.size(); i++)
        {
            s = arr[i];
            mp2[s]++; 
            if(mp[s] != 0){
                mp.erase(s);
            }
            else{
                mp[s] = i;  
            }
            cout<<mp[s]<<"\t"<<s<<endl;
        }
        // cout<<endl;
        for (auto i: mp)
        {
            if(mp2[i.first]==1)
                {
                    v.push_back(i.second);
                    cout<<i.first<<"\t"<<i.second<<endl;
                }
        }
        sort(v.begin(),v.end());
        for (int i = 0; i < v.size(); i++)
        {
            k--;
            if(k == 0){
                return arr[v[i]];
            }
        }
        return "";
    }
};