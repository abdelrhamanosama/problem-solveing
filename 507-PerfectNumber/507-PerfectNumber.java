// Last updated: 6/10/2026, 11:48:48 AM
class Solution {
    public boolean checkPerfectNumber(int num) {
        int sum = 0;
        for(int i = 1; i <= num/2; i++ )
            {
                if(num % i == 0)
                    sum += i;
                if(sum > num)
                    return false;
            }
        return (sum == num);
    }
}