// Last updated: 6/10/2026, 11:45:07 AM
class Solution {
    public int minMoves(int[] nums, int limit) {
        int n = nums.length;
        int ans = (int)1e9;
       int diff[] = new int[2*limit + 2];
        for(int i = 0 ; i < n/2; i++){
            int a = nums[i];
            int b = nums[n-1-i];
            int sum = a+b;
            int low = Math.min(a,b) + 1;
            int high = Math.max(a,b) + limit;
            diff[2]+=2;
            diff[2*limit + 1]-=2;
            diff[low]-=1;
            diff[high+1]+=1;
            diff[sum]-=1;
            diff[sum+1]+=1;
        }
        for(int i = 2; i <=2*limit; i++)
            {
                diff[i] +=diff[i-1];
                ans = Math.min(diff[i] , ans); 
            }
            return ans;
    }
}