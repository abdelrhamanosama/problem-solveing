// Last updated: 6/25/2026, 5:41:20 PM
1#include <bits/stdc++.h>
2#include <ext/pb_ds/assoc_container.hpp>
3using namespace __gnu_pbds;
4typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
5class Solution {
6public:
7    long long countMajoritySubarrays(vector<int>& nums, int target) {
8      int n = nums.size();
9        vector<long long>pref(n+1 , 0);
10        ordered_multiset ms;
11        for(int i = 0 ; i < n; i++)    
12          {
13            pref[i+1] = pref[i] + (nums[i]==target ? 1 : -1);
14          }
15        // for(int i = 0 ; i <= n ; i++) ms.insert(pref[i]);
16        long long cnt = 0;
17        ms.insert(pref[0]);
18        for(int i =1; i <= n; i++){
19          cnt+=ms.order_of_key(pref[i]);
20        //   cout<<ms.order_of_key(pref[i])<<"\t"<<pref[i]<<"\n";
21          ms.insert(pref[i]);
22        }
23        return cnt;
24    }
25};