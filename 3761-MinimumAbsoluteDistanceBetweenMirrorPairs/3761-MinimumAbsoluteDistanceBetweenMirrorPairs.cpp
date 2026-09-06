// Last updated: 9/6/2026, 2:12:23 PM
class Solution {
public:
    int reverseNum(int x) {
        int r = 0;
        while (x) {
            r = r * 10 + x % 10;
            x /= 10;
        }
        return r;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        // build map
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        int mn = 1e9;
        for (int i = 0; i < n; i++) {
            int rev = reverseNum(nums[i]);
            if (!mp.count(rev)) continue;
            auto &v = mp[rev];
            // first index >= i
            auto it = upper_bound(v.begin(), v.end(), i) - v.begin();
            if(it >= v.size()) continue;
            cout<<v[(it)]<<"\t"<<i<<"\t"<<nums[i]<<"\n";
            if(v[it] > i)
                mn = min(mn ,abs(i - v[it]));
            if(it-1>=0 && v[it-1] > i)
                mn = min(mn ,abs(i - v[it-1]));
            if(it-2>=0 && v[it-2] > i)
                mn = min(mn ,abs(i - v[it-2]));
        }
        return (mn == 1e9 ? -1 : mn);
    }
};