// Last updated: 6/10/2026, 11:41:29 AM
class Solution {
public:
#define all(s) s.begin(), s.end()

    long long modPow(long long a, long long e, long long MOD) {
        long long r = 1 % MOD;
        while (e) {
            if (e & 1)
                r = r * a % MOD;
            a = a * a % MOD;
            e >>= 1;
        }
        return r;
    }

    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        for (int i = 0; i < n; i++)
            mx = max(mx, nums[i]);
        cout << mx << "\n";
        vector<vector<int>> v(mx + 1);
        for (int i = 0; i < n; i++) {
            // if (!(nums[i] & 1))
            v[nums[i]].push_back(i);
        }
        cout << v[mx].size() << "\t" << v[mx / 2].size() << "\n";
        long long cnt = 0, mod = 1e9 + 7;
        for (int i = 1; i <= mx; i++) {
            long long ans = 0, k = i / 2;
            if (v[i].size() < 2 || (i & 1) || v[k].size() == 0)
                continue;
            cout << "hi" << i << "\n";
            for (int j = 0; j < v[k].size(); j++) {
                // if(v[i][j+1] - v[i][j] == 1) continue;
                auto it1 = upper_bound(all(v[i]), v[k][j]) -
                           v[i].begin(); //  before me
                long long z = v[i].size() - it1;
                // auto it2 = lower_bound(all(v[i]),v[k][j+1]);
                cout << z << "\n";
                // if(it1 == it2) continue;
                // int z = it2 - it1;
                ans = (ans % mod + z * it1 % mod) % mod;
            }
            cnt = (ans % mod + cnt % mod) % mod;
        }
        long long n0 = v[0].size(); // number of zeros
        if (n0 >= 3) {
            long long x = n0 % mod;
            long long comb = x * ((x - 1 + mod) % mod) % mod;
            comb = comb * ((x - 2 + mod) % mod) % mod;
            // multiply by inverse of 6 modulo mod
            long long inv6 = modPow(6, mod - 2, mod);
            comb = comb * inv6 % mod;
            cnt = (cnt + comb) % mod;
        }

        cout << cnt << "\n";
        return cnt % mod;
    }
};