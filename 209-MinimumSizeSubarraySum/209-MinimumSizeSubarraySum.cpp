// Last updated: 6/10/2026, 11:49:45 AM
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
    int minSubArrayLen(int target, vector<int>& nums) {
        int minValue = 1e9, n = nums.size();
        long long sum = 0;
        for (int i = 0, j = 0; i < n; i++)
        {
            sum += nums[i];
            while(sum >= target && j <= i){
                minValue = min(minValue, i-j+1);
                sum -= nums[j++];
            }
        }
        if(minValue == 1e9) return 0;
        return minValue;
    }
};