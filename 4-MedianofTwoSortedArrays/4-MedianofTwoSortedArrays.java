// Last updated: 9/25/2026, 8:03:32 AM
1class Solution {
2    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
3        int [] arr = new int [nums1.length+nums2.length];
4        int k=0;
5        int i=0;
6        int j=0;
7        double mid;
8        while(i<nums1.length && j<nums2.length){
9            if(nums1[i]>nums2[j]){
10                arr[k]=nums2[j];
11                j++;
12                k++;
13            }
14            else {arr[k]=nums1[i];
15            i++;
16            k++;
17            }
18        }
19        if(i==nums1.length){
20            while(j<nums2.length){
21                arr[k]=nums2[j];
22                k++;
23                j++;
24            }
25        }
26        else{
27            while(i<nums1.length){
28                arr[k]=nums1[i];
29                k++;
30                i++;
31            }
32        }
33        if (arr.length % 2 == 0) {
34        mid = (arr[arr.length / 2] + arr[(arr.length / 2) - 1]) / 2.0;
35        } 
36        else {
37        mid = arr[arr.length / 2];
38        }
39
40        return mid;
41    }
42}