// Last updated: 6/10/2026, 11:49:58 AM
class Solution {
    public void rotate(int[] nums, int k) {
        int n = nums.length; 
        k %=n;
        int rem = n-k;
        // if(rem == k) rem++;
        // System.out.println(rem + " " + k);
        int a[] = new int[n];
        for(int o = 0; o+k < n; o++) 
            a[k+o] = nums[o];
        for(int r = rem ; r < n ; r++)
            a[r-rem] = nums[r];
        for(int i = 0 ; i < n; ++i)
            nums[i] = a[i];
        // for(int i = 0 ; i <= n; i++)
        //     System.out.print(a[i] + " ");
    }
}