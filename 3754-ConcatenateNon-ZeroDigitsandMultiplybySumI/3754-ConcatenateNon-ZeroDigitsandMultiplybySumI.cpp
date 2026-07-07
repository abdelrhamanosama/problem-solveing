// Last updated: 7/7/2026, 7:07:04 AM
1class Solution {
2public:
3    long long sumAndMultiply(int n) {
4     
5     int sum = 0;
6     int nn = 0;
7     while(n){
8        int digit = n%10;
9        n/=10;
10        sum+=digit;
11        if(digit)
12        nn = nn*10 + digit;
13     } 
14     string s = to_string(nn);
15     reverse(s.begin() , s.end());
16     nn = stoi(s);
17     return nn*1ll*sum;  
18    }
19};