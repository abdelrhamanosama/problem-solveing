// Last updated: 6/10/2026, 11:49:07 AM
class Solution {
public:
    vector<long long> v;

void init() {
    v.push_back(0);
    long long x = 9;
    for (int i = 1; i <= 10; i++) {
        v.push_back(x);
        x *= 10;
    }
}

int solve(long long k) {
    init();
    long long x = 0;
    long long digits = 0;
    long long rem = 0;

    for (int i = 1; i < v.size(); i++) {

        long long block = v[i] * i;

        if (k <= block) {
            digits = i;
            long long full = k / digits;
            rem = k % digits;

            x = (long long)pow(10, digits - 1) + full - 1;
            break;
        }
        k -= block;
    }

    if (rem > 0) {
        long long nxt = x + 1;
        string s = to_string(nxt);
        
        return (s[rem - 1]-'0');
    }
    else{
        string s = to_string(x);
        return (s[s.size() - 1]-'0');
    }
}
    int findNthDigit(int n) {
        return solve(n);   
    }
};