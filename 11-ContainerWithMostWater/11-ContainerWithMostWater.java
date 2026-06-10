// Last updated: 6/10/2026, 11:51:21 AM
class Solution {
    public int maxArea(int[] height) {
        int start = 0 , end = height.length - 1 , Area = 0 , max = 0 ; 
        while(start!=end)
        {
            Area = (int)Math.min(height[start], height[end])*(end -start);
            if(Area > max )
                max = Area;
            if(height[start] > height[end])
                end--;
            else
                start++;
        }          
        return max ;
    }
    
}