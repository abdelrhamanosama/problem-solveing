// Last updated: 10/20/2026, 6:14:29 PM
1class Solution {
2public:
3    int sortableIntegers(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> fac;
6
7        for (int x = 1; x * x <= n; ++x) {
8            if (n % x == 0) {
9                fac.push_back(x);
10                if (n / x != x) {
11                    fac.push_back(n / x);
12                }
13            }
14        }
15
16        vector<int> target = nums;
17        ranges::sort(target);
18
19        // Check whether cyclic rotations of nums1 can produce nums2
20        auto check = [](const vector<int>& nums1, const vector<int>& nums2) {
21            int L = nums1.size();
22
23            for (int i = 0; i < L - 1; ++i) {
24                if (nums1[i] > nums1[i + 1]) {
25                    vector<int> rotated;
26                    rotated.insert(rotated.end(), nums1.begin() + i + 1,
27                                   nums1.end());
28                    rotated.insert(rotated.end(), nums1.begin(),
29                                   nums1.begin() + i + 1);
30                    return rotated == nums2;
31                }
32            }
33
34            return nums1 == nums2;
35        };
36
37        int ans = 0;
38
39        for (int d : fac) {
40            bool allGood = true;
41            for (int left = 0; left < n; left += d) {
42                int right = left + d - 1;
43
44                vector<int> sub1(nums.begin() + left, nums.begin() + right + 1);
45                vector<int> sub2(target.begin() + left,
46                                 target.begin() + right + 1);
47
48                if (!check(sub1, sub2)) {
49                    allGood = false;
50                    break;
51                }
52            }
53            if (allGood) {
54                ans += d;
55            }
56        }
57
58        return ans;
59    }
60};