// Last updated: 9/6/2026, 2:12:39 PM
class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        sort(nums.begin() , nums.end() , [] (auto x , auto y){
            if(abs(x) > abs(y)) return 1;
            else  return 0;
        });
        // for(auto x:nums) cout<<x<<" ";
        int n = nums.size();
        long long ans1 = nums[0];
        long long ans2 = nums[1];
        long long ans3 = ans1*ans2;
        if(ans3 > 0) ans3 *= 1e5;
        else ans3*=-1e5;
        return ans3;
    }
};