// Last updated: 6/10/2026, 11:42:36 AM
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
        long long countGood(vector<int>& nums, int k) {
        long long counter = 0, totalPairs = 0;
        int i, j = 0, n = nums.size();
        map<int, int>mp;
        for (int i = 0; i < n; i++)
        {
            totalPairs -= mp[nums[i]]*(mp[nums[i]]-1)/2;
            mp[nums[i]]++;
            totalPairs += mp[nums[i]]*(mp[nums[i]]-1)/2;
            if(totalPairs >= k) {
                // counter++;
                while(totalPairs >= k && j < i){
                    counter+=(n - i);
                    totalPairs -= mp[nums[j]]*(mp[nums[j]]-1)/2;
                    mp[nums[j]]--;
                    totalPairs += mp[nums[j]]*(mp[nums[j]]-1)/2;
                    j++;
                    
            }
            }
        }
        return counter;  
    }
};