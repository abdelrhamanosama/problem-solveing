// Last updated: 9/17/2026, 10:06:46 PM
1class Solution {
2public:
3    int minOperations(int n) {
4        int count = 0;
5
6        while(n > 0) {
7
8            // If n is even, its binary representation ends in 0.
9            // Divide by 2 to remove this trailing zero. (Doesnt count as an operation)
10            if(n % 2 == 0) {
11                n /= 2;
12            }
13
14            // Special case: 1 can be reduced to 0 in one operation. (last step so we break out and return count)
15            else if(n == 1) {
16                count++;
17                break;
18            }
19
20            // Binary ends in 01.
21            // Subtracting 1 changes 01 -> 00.
22            else if(n % 4 == 1) {
23                n--;
24                count++;
25            }
26
27            // Binary ends in 11.
28            // Adding 1 turns the trailing 11s into zeros.
29            else {
30                n++;
31                count++;
32            }
33        }
34
35        return count;
36    }
37};