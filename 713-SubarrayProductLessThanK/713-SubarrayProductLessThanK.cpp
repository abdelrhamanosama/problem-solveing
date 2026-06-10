// Last updated: 6/10/2026, 11:48:06 AM
#pragma GCC optimize("Ofast","inline","fast-math","unroll-loops","no-stack-protector","-ffast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();
class Solution {
public:
 int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    int counter = 0;
    int n = nums.size();
    int mul = 1;
    int i, j = 0;
    if(k <= 1) return 0;
    for (i = 0; i < n; i++)
    {
        mul *= nums[i];
        while(mul >= k) mul /= nums[j++];
        counter += 1 + (i-j);
    }
    return counter;
}
};