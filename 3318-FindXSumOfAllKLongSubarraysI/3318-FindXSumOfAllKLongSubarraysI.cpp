// Last updated: 9/6/2026, 2:15:16 PM
class Solution {
public:
    vector<int> findXSum(vector<int>& v, int k, int x) {
        map<int,int> mp;
        vector<int> ans;
        int n = v.size();

        // build first window
        for (int i = 0; i < k; i++) mp[v[i]]++;

        auto getSum = [&](map<int,int>& mp, int x) {
            vector<pair<int,int>> a;
            for (auto &p : mp) a.push_back({p.second, p.first});
            sort(a.begin(), a.end(), [](auto &A, auto &B){
                if (A.first != B.first) return A.first > B.first;  // higher freq first
                return A.second > B.second;                        // higher value if tie
            });

            long long sum = 0;
            int i = 0;
            while (i < (int)a.size() && x > 0) {
                int freq = a[i].first;
                int val  = a[i].second;
                sum += 1LL * freq * val;
                x--; // take only one value per frequency group
                // skip all with same frequency
                // cout<<freq<<" "<<val<<"\n";
                i++;
                // while (i < (int)a.size()) i++;
            }
            return (int)sum;
        };

        ans.push_back(getSum(mp, x));
        // cout<<"end\n";

        for (int i = k; i < n; i++) {
            mp[v[i - k]]--;
            if (mp[v[i - k]] == 0) mp.erase(v[i - k]);
            mp[v[i]]++;
            ans.push_back(getSum(mp, x));
        }

        return ans;
    }
};
