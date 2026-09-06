// Last updated: 9/6/2026, 2:15:27 PM
class Solution {
#define all(s) s.begin(), s.end()

public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
      int mx = *max_element(all(nums));
      vector<long long> cnt(mx + 1, 0) , gcd(mx+1 , 0);
      for(auto x:nums) cnt[x]++;
      for(int i = mx; i > 0; i--)
        {
          long long sum = 0;
          for(int j = i; j <=mx ; j+=i)
            {
              sum+=cnt[j];
              gcd[i]-=gcd[j];
            }
            gcd[i]+=sum*(sum-1)/2;
        }
        
        partial_sum(all(gcd) ,gcd.begin());
        vector<int> ans;
        for(auto x: queries)
          {
            int idx = upper_bound(all(gcd) , x) - gcd.begin();
            ans.push_back(idx);
          }
        return ans;
    }
};