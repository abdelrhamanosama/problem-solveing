// Last updated: 9/6/2026, 2:14:32 PM
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<int> s(4096,0);
        vector<int> triples(4096,0);
        vector<int> pairs;
        for(int i = 0 ; i < nums.size(); i++)
          for(int j = 0 ; j < nums.size() ; j++)
            s[(nums[i]^nums[j])]++;
        
        for(int i = 0; i < 4096; i++)
        if(s[i]) pairs.push_back(i);
        
        for(int i = 0; i < nums.size(); i++)
          for(int j = 0; j < pairs.size(); j++)
            triples[(pairs[j]^nums[i])]++;
        int ans = 0;
        for(int i = 0; i < 4096; i++)
            ans+=(triples[i] > 0);
        return ans;
    }
};