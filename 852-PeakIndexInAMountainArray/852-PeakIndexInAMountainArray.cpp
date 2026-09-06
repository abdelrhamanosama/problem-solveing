// Last updated: 9/6/2026, 4:01:02 PM
class Solution {
#define sz(s) (int)(s).size()
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;        
        int right = sz(arr) - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(arr[mid] < arr[mid + 1]){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return left;
    }

};