// Last updated: 9/6/2026, 3:43:29 PM
1class Solution {
2public:
3    int largestInteger(vector<int>& nums, int k) {
4
5        int n = nums.size();
6
7        unordered_map<int, int> windowCount;
8
9        for (int l = 0; l + k <= n; l++) {
10
11            unordered_set<int> seen;
12
13            for (int i = l; i < l + k; i++) {
14                seen.insert(nums[i]);
15            }
16
17            for (int x : seen) {
18                windowCount[x]++;
19            }
20        }
21
22        int ans = -1;
23
24        for (auto& [x, cnt] : windowCount) {
25            if (cnt == 1) {
26                ans = max(ans, x);
27            }
28        }
29
30        return ans;
31    }
32};