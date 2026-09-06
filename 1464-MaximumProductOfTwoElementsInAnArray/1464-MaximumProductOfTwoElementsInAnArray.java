// Last updated: 9/6/2026, 2:24:24 PM
class Solution {
    public int maxProduct(int[] nums) {
        int mx1 = 0 ,mx2 = 0;
        for(int i: nums){
            if(mx1 < i){
                mx2 = mx1;
                mx1 = i;
            }
            else if(mx2 < i) 
                mx2 = i;

        }
        return (mx1-1)*(mx2-1);
    }
}