// Last updated: 9/7/2026, 2:40:54 AM
1class Solution {
2public:
3    vector<int> productExceptSelf(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> pref,suff(n+1,1),ans;
6        pref.push_back(1);
7        for(int i = 0; i <n; i++){
8            pref.push_back(pref.back()*nums[i]);
9        }
10        for(int i = n-1; i>=0; i--){
11            suff[i]*=suff[i+1]*nums[i];
12        }
13        for(int i = 0; i < n; i++){
14            ans.push_back(pref[i]*suff[i+1]);
15        }
16        return ans;
17    }
18};