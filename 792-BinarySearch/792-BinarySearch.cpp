// Last updated: 6/10/2026, 11:47:54 AM
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