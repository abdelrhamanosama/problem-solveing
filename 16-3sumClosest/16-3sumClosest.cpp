// Last updated: 6/10/2026, 11:51:14 AM
class Solution {
#define all(s) s.begin(),s.end()

public:
    int threeSumClosest(vector<int>& nums, int target) {
    int mn = 1e9 ,suo = 0;
    sort(all(nums));
    for(int  i = 0 ; i < nums.size(); i++){
        int l = i + 1;
        int r = nums.size() - 1;
        while(l  < r){
            int a = nums[i];
            int b = nums[l];
            int c = nums[r];
            int  sum = a+b+c;
            int diff = abs(target - sum);
            if(diff == 0) return target;
            if(diff < mn){
                mn = diff;
                suo = sum;
            }
            if(sum > target){
                r--;
            } 
            else {
                l++;
            }
        }
    }        
    return suo;   
    }
};