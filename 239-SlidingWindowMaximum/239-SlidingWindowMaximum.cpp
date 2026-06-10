// Last updated: 6/10/2026, 11:49:31 AM
#pragma GCC optimize("Ofast","inline","fast-math","unroll-loops","no-stack-protector","-ffast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> v;
    deque <int> d;
    for (int i = 0; i < nums.size(); i++)
    {
        while(!d.empty() && d.front() <= i - k)d.pop_front();
        while(!d.empty() && nums[d.back()] <= nums[i]) d.pop_back();
        d.push_back(i);
        if(i >= k-1)
            v.push_back(nums[d.front()]);
    }
    return v;
}
};