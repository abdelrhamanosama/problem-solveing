// Last updated: 11/2/2026, 1:21:49 PM
1class Solution {
2    public int minMoves2(int[] nums) {
3        int sum = 0 ;
4        int n = nums.length;
5        Arrays.sort(nums);
6        for(var x : nums) sum+=x;
7        int val = sum/n;
8        int center = n/2;
9        long   cnt1 = 0,cnt2 = 0;
10        // System.out.println(sum*1.0/n);
11        // System.out.println(val);
12        for(var x : nums){
13            cnt1 += Math.abs(x-val);
14            cnt2 += Math.abs(x-nums[center]);
15        }
16        return (int)Math.min(cnt1 , cnt2);
17    }
18}