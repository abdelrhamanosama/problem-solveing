// Last updated: 6/10/2026, 11:51:02 AM
class Solution {
#define sz(s) (int)(s).size()
public:
    int search(vector<int>& nums, int target) {
        if(sz(nums) == 1){
            if(nums[0] == target) return 0;
            else return -1;
        }
        int left = 0;        
        int right = sz(nums) - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[right]){
                left = mid + 1;
            }else{
                right = mid;
            }
        }

        int k = left;
        // if(k == sz(nums)) k = 0;
        // else k--;
        cout<<k;
        if(nums[sz(nums)-1]>= target){
            if(k == sz(nums))
                left = 0;
            else left = k;
            right = sz(nums)-1;
            while(left<=right){
                int mid = (left+right)/2;
                if(nums[mid] == target) return mid;
                else if(nums[mid] > target) right = mid - 1;
                else left = mid + 1;
            }
        }
        else {
            left = 0;
            right = k-1;
            while(left<=right){
                int mid = (left+right)/2;
                if(nums[mid] == target) return mid;
                else if(nums[mid] > target) right = mid - 1;
                else left = mid + 1;
            }
        }
        return  -1;
    }
};