// Last updated: 7/24/2026, 7:24:34 PM
1class Solution {
2public:
3    int uniqueXorTriplets(vector<int>& nums) {
4        vector<int> s(4096,0);
5        vector<int> triples(4096,0);
6        vector<int> pairs;
7        for(int i = 0 ; i < nums.size(); i++)
8          for(int j = 0 ; j < nums.size() ; j++)
9            s[(nums[i]^nums[j])]++;
10        
11        for(int i = 0; i < 4096; i++)
12        if(s[i]) pairs.push_back(i);
13        
14        for(int i = 0; i < nums.size(); i++)
15          for(int j = 0; j < pairs.size(); j++)
16            triples[(pairs[j]^nums[i])]++;
17        int ans = 0;
18        for(int i = 0; i < 4096; i++)
19            ans+=(triples[i] > 0);
20        return ans;
21    }
22};