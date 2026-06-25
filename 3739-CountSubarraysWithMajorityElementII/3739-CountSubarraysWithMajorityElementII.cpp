// Last updated: 6/25/2026, 6:33:38 PM
1class Solution {
2public:
3      long long countMajoritySubarrays(vector<int>& nums, int target) {
4        int n = nums.size();
5        vector<int> freq(2*n+1 , 0);
6        freq[n] = 1;
7        long long less = 0 , ans = 0 , curr = n; 
8        for(auto x: nums){
9          if(x == target){
10            less += freq[curr++];
11          }
12          else {
13            less-=freq[--curr];
14          }
15          freq[curr]++;
16          ans +=less;
17        }  
18        return ans;
19    }
20};