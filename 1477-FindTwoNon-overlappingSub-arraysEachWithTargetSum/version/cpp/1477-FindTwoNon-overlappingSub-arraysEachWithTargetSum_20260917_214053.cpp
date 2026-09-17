// Last updated: 9/17/2026, 9:40:53 PM
1/* صلِّ على النبي */
2#include <bits/stdc++.h>
3
4#include <ext/pb_ds/assoc_container.hpp>
5using namespace __gnu_pbds;
6using namespace std;
7#define ll long long
8#define sz(s) (int)(s).size()
9#define all(s) s.begin(), s.end()
10
11class Solution {
12public:
13    int minSumOfLengths(vector<int>& arr, int target) {
14        int n = arr.size();
15
16        vector<int> pref(n + 1, 0);
17        vector<pair<int, int>> lengthes;
18
19        for (int i = 1; i <= n; i++)
20            pref[i] = pref[i - 1] + arr[i - 1];
21
22        for (int i = 0; i < n; i++) {
23            int l = i + 1;
24            int r = n;
25            int ans = 1e9;
26
27            while (l <= r) {
28                int mid = (l + r) >> 1;
29
30                if (pref[mid] - pref[i] == target) {
31                    ans = mid - i;
32                    r = mid - 1;
33                }
34                else if (pref[mid] - pref[i] > target) {
35                    r = mid - 1;
36                }
37                else {
38                    l = mid + 1;
39                }
40            }
41
42            if (ans != 1e9)
43                lengthes.push_back({i, ans});
44        }
45
46        if (lengthes.size() < 2)
47            return -1;
48
49        sort(all(lengthes));
50
51        vector<vector<int>> mem(lengthes.size(),
52                                vector<int>(3, -1));
53
54        auto dp = [&](auto&& self, int i, int cnt) -> int {
55
56            if (cnt == 0)
57                return 0;
58
59            if (i >= lengthes.size())
60                return 1e9;
61
62            int& ret = mem[i][cnt];
63
64            if (ret != -1)
65                return ret;
66
67            ret = 1e9;
68
69            // Take
70            int start = lengthes[i].first;
71            int len = lengthes[i].second;
72
73            int end = start + len;
74
75            int lo = lower_bound(
76                all(lengthes),
77                make_pair(end, -1)
78            ) - lengthes.begin();
79
80            int take = len + self(self, lo, cnt - 1);
81
82            // Skip
83            int skip = self(self, i + 1, cnt);
84
85            return ret = min(take, skip);
86        };
87
88        int ans = dp(dp, 0, 2);
89
90        return ans >= 1e9 ? -1 : ans;
91    }
92};