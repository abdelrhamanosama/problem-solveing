// Last updated: 9/6/2026, 2:13:29 PM
/* صلِّ على النبي */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:

    struct LinearSieve {

        int n;
        vector<int> spf;
        vector<int> primes;

        LinearSieve(int n) {

            this->n = n;

            spf = vector<int>(n + 1, 0);

            build();
        }

        void build() {

            spf[0] = spf[1] = 1;

            for (int i = 2; i <= n; i++) {

                if (spf[i] == 0) {
                    spf[i] = i;
                    primes.push_back(i);
                }

                for (int p : primes) {

                    if (p > spf[i] || 1LL * i * p > n)
                        break;

                    spf[i * p] = p;
                }
            }
        }
    };

    vector<int> factorize(int x, vector<int>& spf)
    {
        vector<int> factors;

        while (x > 1)
        {
            int p = spf[x];

            factors.push_back(p);

            while (x % p == 0)
                x /= p;
        }

        return factors;
    }

public:

    int minJumps(vector<int>& nums)
    {
        int n = nums.size();

        int mx = *max_element(nums.begin(), nums.end());

        LinearSieve ls(mx);

        // prime -> indices divisible by it
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++)
        {
            auto facts = factorize(nums[i], ls.spf);

            for (auto p : facts)
            {
                mp[p].push_back(i);
            }
        }

        queue<int> q;

        vector<int> distance(n, -1);

        q.push(0);

        distance[0] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            if (node == n - 1)
                return distance[node];

            // move left
            if (node - 1 >= 0 && distance[node - 1] == -1)
            {
                distance[node - 1] = distance[node] + 1;
                q.push(node - 1);
            }

            // move right
            if (node + 1 < n && distance[node + 1] == -1)
            {
                distance[node + 1] = distance[node] + 1;
                q.push(node + 1);
            }

            // teleportation allowed only if nums[node] is prime
            if (ls.spf[nums[node]] == nums[node])
            {
                int p = nums[node];

                for (auto nxt : mp[p])
                {
                    if (distance[nxt] != -1)
                        continue;

                    distance[nxt] = distance[node] + 1;

                    q.push(nxt);
                }

                // important optimization
                mp[p].clear();
            }
        }

        return -1;
    }
};