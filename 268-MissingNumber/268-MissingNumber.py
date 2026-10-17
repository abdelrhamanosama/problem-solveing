# Last updated: 10/18/2026, 2:08:33 AM
1class Solution(object):
2    def missingNumber(self, nums):
3        n = len(nums)
4        i = 0
5        while i <= n : 
6            if(not i in nums) : 
7                return i
8            i+=1
9        