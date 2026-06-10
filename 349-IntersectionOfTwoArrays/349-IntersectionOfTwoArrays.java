// Last updated: 6/10/2026, 11:49:16 AM
import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
       int freq[] = new int[1000];
       List<Integer> list = new ArrayList<Integer>();
        for (int i = 0; i < nums1.length; i++)
           if(freq[nums1[i]] == 0)
               freq[nums1[i]]++;
        for (int i = 0; i < nums2.length; i++)
            if(freq[nums2[i]] > 0) {
                list.add(nums2[i]);
                freq[nums2[i]] = -1;
            }
        int arr [] = new int[list.size()];
        for (int i = 0; i < list.size(); i++)
            arr[i] = list.get(i);
        return arr;
    }
}