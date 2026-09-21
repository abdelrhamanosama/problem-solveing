// Last updated: 9/22/2026, 12:20:13 AM
1class Solution {
2public:
3    vector<long long> resultArray(vector<int>& nums, int k) {
4
5        int n = nums.size();
6        vector<long long> ans(k);
7
8        for (int rem = 0; rem < k; rem++) {
9
10            // dp(i, product)
11            // number of valid subarrays that START at i
12            // and whose current product is `product`
13            vector<vector<long long>> mem(
14                n + 2,
15                vector<long long>(k+1, -1)
16            );
17
18            auto dp = [&](auto&& self, int i, int product) -> long long {
19
20                if (i >= n)
21                    return 0;
22
23                long long &ret = mem[i][product];
24
25                if (ret != -1)
26                    return ret;
27
28                int newProduct =
29                    (1LL * product * nums[i]) % k;
30
31                // Current subarray [start ... i]
32                long long take =
33                    (newProduct == rem);
34
35                // Continue extending it
36                take += self(self, i + 1, newProduct);
37
38                return ret = take;
39            };
40
41            // Start a new subarray at every position
42            for (int start = 0; start < n; start++) {
43
44                nums[start] %= k;
45
46                ans[rem] += dp(dp, start, 1);
47            }
48        }
49
50        return ans;
51    }
52};