# Last updated: 10/13/2026, 11:36:26 AM
1class Solution(object):
2    def isPalindrome(self, x):
3        num=str(x)
4        num2=num[::-1]
5        if num2 == num :
6            return True
7        else :
8            return False