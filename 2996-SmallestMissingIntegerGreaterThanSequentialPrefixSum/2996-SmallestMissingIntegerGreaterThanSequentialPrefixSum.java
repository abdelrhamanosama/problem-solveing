// Last updated: 8/12/2026, 1:51:47 AM
1
2class Solution {
3    public int missingInteger(int[] nums) {
4        int n = nums.length;
5        Set<Integer> numSet = new HashSet<>(n);
6        int total = nums[0];
7        for(var num :nums) numSet.add(num);
8        for(int i = 1 ; i< n; i++){
9            if(nums[i] == nums[i-1]+1)
10                total+=nums[i];
11            else
12                break;
13        }
14        while(numSet.contains(total)) total++;
15        return total;
16    }
17}