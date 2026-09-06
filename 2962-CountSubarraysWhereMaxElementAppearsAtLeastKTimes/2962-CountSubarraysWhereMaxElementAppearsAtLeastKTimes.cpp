// Last updated: 9/6/2026, 2:16:40 PM
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxValue = 0, counter = 0, n = nums.size();
        long long count = 0;
        for (int i = 0; i < n; i++)
                maxValue = max(maxValue,nums[i]);
        for (int i = 0, j = 0; i < n; i++)
        {
            if(nums[i] == maxValue) counter++;
            while(counter >= k){
                count += n - i;
                if(nums[j] == maxValue)
                         counter--;
                j++;
                cout<<count<<"\t";
            }
            cout<<"hi\n";
        }
        return count;
    }
};