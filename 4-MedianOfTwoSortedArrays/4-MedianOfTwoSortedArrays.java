// Last updated: 6/10/2026, 11:51:27 AM
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int [] arr = new int [nums1.length+nums2.length];
        int k=0;
        int i=0;
        int j=0;
        double mid;
        while(i<nums1.length && j<nums2.length){
            if(nums1[i]>nums2[j]){
                arr[k]=nums2[j];
                j++;
                k++;
            }
            else {arr[k]=nums1[i];
            i++;
            k++;
            }
        }
        if(i==nums1.length){
            while(j<nums2.length){
                arr[k]=nums2[j];
                k++;
                j++;
            }
        }
        else{
            while(i<nums1.length){
                arr[k]=nums1[i];
                k++;
                i++;
            }
        }
        if (arr.length % 2 == 0) {
        mid = (arr[arr.length / 2] + arr[(arr.length / 2) - 1]) / 2.0;
        } 
        else {
        mid = arr[arr.length / 2];
        }

        return mid;
    }
}