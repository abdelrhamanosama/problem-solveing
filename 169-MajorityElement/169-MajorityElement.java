// Last updated: 6/10/2026, 11:50:06 AM
import java.util.Arrays;
class Solution {
    public int majorityElement(int[] nums) {
         HashMap<Integer,Integer> map = new HashMap<>();
         int major= 0;
         int n= nums.length/2;
         for(int i =0;i<nums.length;i++){
             map.put(nums[i],map.getOrDefault(nums[i],0)+1);
             if(map.get(nums[i])>n){
                 major= nums[i];
                 break;
             }
         }
         return major;
        }
}