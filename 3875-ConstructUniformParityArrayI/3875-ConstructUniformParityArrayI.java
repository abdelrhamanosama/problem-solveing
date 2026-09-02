// Last updated: 9/2/2026, 6:17:42 AM
1class Solution {
2    public boolean uniformArray(int[] nums1) {
3        int countEven = 0 , countOdd = 0 , n = nums1.length;
4        for(int x: nums1){
5            if(x%2 == 1) countOdd++;
6            else countEven++;
7        }
8        return n == countEven|| countOdd == n || n <= countEven + (countOdd*(countOdd + 1)/2) ||  
9        n <= countOdd + ((int)Math.abs(countOdd-countEven)*((int)Math.abs(countOdd-countEven) + 1)/2);
10    }
11}