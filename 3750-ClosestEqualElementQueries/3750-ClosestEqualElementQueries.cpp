// Last updated: 6/10/2026, 11:41:42 AM
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size() , m = queries.size();
        unordered_map<int, vector<int>> mp;

        // build map
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        vector<int> ans(m);
        for(int i = 0 ; i < m; i ++){
            int mn = 1e9, x = queries[i];
            if(mp[nums[x]].size() > 1) {
                auto &v = mp[nums[x]];
                auto it = lower_bound(v.begin() , v.end() , x)-v.begin();
                if(it <v.size()){
                    if(it > 0 && it < v.size() -1){
                        mn = min(mn, abs(x-v[it-1]));
                        mn = min(mn, abs(x-v[it+1]));
                    }
                    else if(it == 0 && v.size() == 2){
                        mn = min(mn, abs(x-v[it+1]));
                        mn = min(mn, abs(n+x-v[it+1]));

                    }
                    else if(it == v.size()-1 && v.size() == 2){
                        mn = min(mn, abs(n-x+v[it-1]));
                        mn = min(mn, abs(x-v[it-1]));
                    }
                    else if(it == 0 && v.size() > 2){
                        mn = min(mn, abs(x+n-v.back()));
                        mn = min(mn, abs(x-v[it+1]));
                    }
                    else if(it == v.size() -1 && v.size() > 2){
                        mn = min(mn, abs(x-v[it-1]));
                        mn = min(mn, abs(n-x+v[0]));
                    }
                }
            }
            ans[i] = (mn == 1e9 ? -1 : mn);
        }
        return ans;
    }
};