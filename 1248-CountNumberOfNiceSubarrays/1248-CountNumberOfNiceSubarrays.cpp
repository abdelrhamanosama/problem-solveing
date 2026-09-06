// Last updated: 9/6/2026, 3:58:09 PM
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i, j = 0, odd = 0, count , total = 0;
        int n = nums.size();
        for(i = 0; i < n; i++){
            if(nums[i]&1)
            {
                odd++;
                if(odd >= k){
                    count = 1;
                    while(!(nums[j++]&1)) count++;
                    total += count;
                }
            }
            else if(odd >= k)  total += count;
        }
        return total;
    }
};