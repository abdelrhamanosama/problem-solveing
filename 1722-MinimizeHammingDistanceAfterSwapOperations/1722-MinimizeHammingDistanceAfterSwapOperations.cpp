// Last updated: 9/6/2026, 2:21:44 PM
class Solution {
    #define all(s) s.begin(),s.end()
public:
    struct DSU {
        vector<int> p;

        DSU(int n) {
            p.resize(n);
            for (int i = 0; i < n; i++) p[i] = i;
        }

        int find(int x) {
            if (p[x] == x) return x;
            return p[x] = find(p[x]);
        }

        void merge(int a, int b) {
            a = find(a);
            b = find(b);
            if (a != b) p[b] = a;
        }
    };

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DSU dsu(n);

        // build components
        for (auto &v : allowedSwaps) {
            dsu.merge(v[0], v[1]);
        }

        // group indices by component
        unordered_map<int, vector<int>> comp;
        for (int i = 0; i < n; i++) {
            comp[dsu.find(i)].push_back(i);
        }
        int ans = 0;
        for(auto [x , indecies] : comp){
                unordered_map<int,int> mp;
                for(int i  : indecies) mp[source[i]]++;
                for(int i : indecies) 
                    if(mp[target[i]] > 0) {
                        mp[target[i]]--;
                    }
                    else {
                        ans++;
                    }
        }

        return ans;
    }
};