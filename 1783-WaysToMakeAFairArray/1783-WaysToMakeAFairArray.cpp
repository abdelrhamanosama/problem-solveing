// Last updated: 6/10/2026, 11:45:18 AM
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int ev = 0 , od = 0 , n = nums.size();
        for(int i = 0; i < n ;i++){
            if((i)&1) od += nums[i];
            else ev += nums[i];
        }
        int oldev = 0 , oldod = 0;
        int cnt = 0;
        for(int i = 0 ; i < n; i++)
            {
                if(i&1) od-=nums[i];
                else ev -= nums[i];

                if(oldod + ev == oldev + od) cnt++;    

                if((i)&1) oldod += nums[i];
                else oldev += nums[i];
            }
        return cnt;
    }
};