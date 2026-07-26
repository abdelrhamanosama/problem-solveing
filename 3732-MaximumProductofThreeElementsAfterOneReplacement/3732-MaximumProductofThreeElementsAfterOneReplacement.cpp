// Last updated: 7/26/2026, 3:08:54 PM
1class Solution {
2public:
3    long long maxProduct(vector<int>& nums) {
4        sort(nums.begin() , nums.end() , [] (auto x , auto y){
5            if(abs(x) > abs(y)) return 1;
6            else  return 0;
7        });
8        // for(auto x:nums) cout<<x<<" ";
9        int n = nums.size();
10        long long ans1 = nums[0];
11        long long ans2 = nums[1];
12        long long ans3 = ans1*ans2;
13        if(ans3 > 0) ans3 *= 1e5;
14        else ans3*=-1e5;
15        return ans3;
16    }
17};