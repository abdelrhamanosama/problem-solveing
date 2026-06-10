// Last updated: 6/10/2026, 11:49:43 AM
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int freq[20005] = {};
        for(int i = 0 ; i < nums.size(); i++)
            freq[nums[i]+10000]++;
        for(int i = 20004; i >= 0; i--)
            {
                if(k > freq[i])
                    k-=freq[i];
                else
                    return i-10000;
            }
        return 0;
    }
};