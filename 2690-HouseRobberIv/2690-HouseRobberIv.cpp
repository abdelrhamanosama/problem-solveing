// Last updated: 6/10/2026, 11:42:31 AM
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        long long l = 1 , r = 1e9 , n = nums.size() ,ans = 1e9;
        while(l < r){
            long long mid = (l+r)/2;
            int takes = 0;
            for(int i = 0 ; i < n; i++)
                if(mid >= nums[i]){
                    takes++;
                    i++;
                }
            if(takes >= k) r = mid , ans = mid;
            else l = mid+1;
        }
        return l;
    }
};