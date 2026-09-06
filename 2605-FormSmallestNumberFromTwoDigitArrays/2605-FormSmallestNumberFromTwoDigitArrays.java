// Last updated: 9/6/2026, 2:17:49 PM
class Solution {
    public int minNumber(int[] nums1, int[] nums2) {
        int freq[] = new int[10];
        int min1 = 10, min2 = 10, min3 = 10;
        for(int i = 0; i < nums1.length; i++) {
            freq[nums1[i]]++;
            if(min1 > nums1[i])
                    min1 = nums1[i];
        }
        for(int i = 0; i < nums2.length; i++) {
            freq[nums2[i]]++;
            if(min2 > nums2[i])
                    min2 = nums2[i];
        }
        for(int i = 0; i <= 9; i++) {
            if(freq[i]==2) {
                if(min3 > i)
                    min3 = i;
            }
        }
        if(min3 != 10) return min3;
        int num1 = min1*10 + min2;
        int num2 = min2*10 + min1;
        return (num1 < num2)? num1 : num2;
    }
}