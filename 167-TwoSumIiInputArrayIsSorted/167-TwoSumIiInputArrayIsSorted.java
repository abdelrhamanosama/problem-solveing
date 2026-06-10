// Last updated: 6/10/2026, 11:50:08 AM
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int l = 0 , r = numbers.length-1; 
        while(l < r){
            if(numbers[l] + numbers[r] > target) r--;
            else if(numbers[l] + numbers[r] < target) l++;
            else break;
        }
        int a[] = { l+1 ,r+1};
        return a;
    }
}