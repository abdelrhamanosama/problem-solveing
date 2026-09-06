// Last updated: 9/6/2026, 2:12:28 PM
class Solution {
public:
    long long sumAndMultiply(int n) {
     
     int sum = 0;
     int nn = 0;
     while(n){
        int digit = n%10;
        n/=10;
        sum+=digit;
        if(digit)
        nn = nn*10 + digit;
     } 
     string s = to_string(nn);
     reverse(s.begin() , s.end());
     nn = stoi(s);
     return nn*1ll*sum;  
    }
};