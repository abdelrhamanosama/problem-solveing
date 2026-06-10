// Last updated: 6/10/2026, 11:49:47 AM
import java.util.Map;
import java.util.HashMap;

class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer , Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; i++) {
            if(map.containsKey(nums[i]))
                {
                    int x = map.get(nums[i]);
                    System.out.println(x + "this is  x \t and i" + i);
                    if((int)Math.abs(x-i) <= k)
                        return true;
                    else
                        map.replace(nums[i], i);
                }
            else
                map.put(nums[i],i);                
        }
        return false;
    }
}