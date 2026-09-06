// Last updated: 9/6/2026, 4:01:26 PM
class Solution {
#define sz(s) (int)(s).size()

public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = sz(nums) - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return -1;
    }
};