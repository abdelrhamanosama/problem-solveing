// Last updated: 9/23/2026, 5:55:01 PM
1class Solution {
2public:
3    int minOperations(vector<int>& nums, int x) {
4        int n = nums.size();
5        vector<int> pref1(n+1,0);
6        vector<int> pref2(n+1 , 0);
7        for(int i = 1; i<=n; i++)
8            {
9                pref1[i]+=pref1[i-1]+nums[i-1];
10                pref2[n-i]+=pref2[n-i+1]+nums[n-i];
11            }
12        reverse(pref2.begin() , pref2.end());
13        int cnt = 1e9;
14        if(x > pref1[n]) return -1;
15        // for(auto x:pref1) cout<<x<<" ";
16        // cout<<"\n";
17        // for(auto x:pref2) cout<<x<<" ";
18        for(int i = 0 ; i <= n; i++)
19            {
20                int pref = pref1[i];
21                if(x-pref == 0)
22                    cnt = min(cnt , i);
23                else if(x-pref > 0){
24                    int target = x-pref;
25                    if(binary_search(pref2.begin() , pref2.end() , target)){
26                        int idx = lower_bound(pref2.begin() , pref2.end() , target) - pref2.begin();
27                        cnt =min(cnt , i +idx);
28                    }
29                }
30            }
31            if(binary_search(pref2.begin() , pref2.end() , x))
32            {
33                int idx = lower_bound(pref2.begin() , pref2.end() , x) - pref2.begin();
34                cnt =min(cnt , idx);
35            }
36            if(binary_search(pref1.begin() , pref1.end() , x))
37            {
38                int idx = lower_bound(pref1.begin() , pref1.end() , x) - pref1.begin();
39                cnt =min(cnt , idx);
40            }
41                return cnt == 1e9 ? -1 : cnt;
42    }
43
44
45};