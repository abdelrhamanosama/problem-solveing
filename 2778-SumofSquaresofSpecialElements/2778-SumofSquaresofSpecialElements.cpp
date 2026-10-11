// Last updated: 10/11/2026, 3:07:40 PM
1class Solution {
2public:
3    int sumOfSquares(vector<int>& nums) {
4        int sum = 0;
5        for(int i = 0 ; i < nums.size(); i++){
6            if(nums.size()%(i+1) == 0) sum += (nums[i]*nums[i]);
7        }
8        return sum;
9    }
10};