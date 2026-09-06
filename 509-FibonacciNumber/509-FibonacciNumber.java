// Last updated: 9/6/2026, 4:00:22 PM
class Solution {
    public int fib(int n) {
        int f1 = 1, f0 = 0, f2 = 0;
        if(n == 0) return 0;
        if(n == 1) return 1;
        for(int i = 2; i <= n; i++)
        {
            f2 = f1+ f0;
            f0 = f1;
            f1 = f2;
        }
        return f2;
    }
}