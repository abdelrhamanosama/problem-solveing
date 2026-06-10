// Last updated: 6/10/2026, 11:50:33 AM
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        if(m==nums1.length) return;
        for(int i = m; i < nums1.length; i++)
            nums1[i] = nums2[i - m];
        Arrays.sort(nums1);        
    }
}