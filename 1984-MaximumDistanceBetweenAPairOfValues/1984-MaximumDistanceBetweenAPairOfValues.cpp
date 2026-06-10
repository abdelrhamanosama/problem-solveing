// Last updated: 6/10/2026, 11:44:28 AM
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        // binary search
        int ans = 0;
        for(int i = 0 ; i < nums1.size(); i++){
            int l = i , r = nums2.size()-1;
            int mx = 0;
            while(l <= r){
                int mid = (l+r)/2;
                if(nums1[i]<=nums2[mid]) {
                    l = mid + 1;
                    mx = max(mx , mid - i);
                }
                else {
                    r = mid-1;
                }
            } 
            ans = max(ans , mx);
        }
        return ans;
    }
};