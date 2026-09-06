// Last updated: 9/6/2026, 2:17:59 PM

import java.util.Arrays;

class Solution {
    public int getCommon(int[] nums1, int[] nums2) {
        for (int i = 0; i < nums1.length;i++) {
           if(Arrays.binarySearch(nums2, nums1[i]) >= 0) return nums1[i];
        }
        return -1;
    }
}