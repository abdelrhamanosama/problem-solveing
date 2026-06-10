// Last updated: 6/10/2026, 11:42:14 AM
import java.util.HashMap;
import java.util.Map;

class Solution {
    public int minOperations(int[] nums) {
        Map<Integer,Integer> map = new HashMap<>();
        for(int i : nums) {
            if(map.get(i) == null)
                map.put(i,1);
            else
                map.put(i,map.get(i)+1);
        }
        System.out.println(map);
        int counter = 0;
        //  we need idea to know how get min in combination 2 and 3
        for (int i : map.keySet()) {
            int num = map.get(i),temp = 0;
            System.out.println(num +" in first");
            if(num == 1)
                return -1;
            else
            {
                if(num%3 == 0)
                    {
                        counter += num/3;
                        continue;
                    }
                else {
                    while (true) { 
                        temp += 2;
                        if((num-temp)%3==0 && num >= temp) {
                            counter += temp/2 + (num-temp)/3; 
                            break;
                        }
                        System.out.println(num + " num");
                        System.out.println(temp + " temp");
                    }
                }
            }
            System.out.println(counter+ " counter");
        }
        return counter;
    }
} 
