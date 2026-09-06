// Last updated: 9/6/2026, 4:01:19 PM
/* صلِّ على النبي */
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define sz(s) (int)(s).size()
#define all(s) s.begin(), s.end()
class Solution
{
private:
int plindrome(int x)
    {
        string s = to_string(x);
        bool f1 = s.find('2') == string::npos && s.find('5') == string::npos && s.find('6') == string::npos && s.find('9') == string::npos;
        bool f2 = (s.find('3') != string::npos || s.find('7') != string::npos || s.find('4') != string::npos );
        cout<<s<<"\t"<<f1 <<" \t"<<f2<<"\n";
        if (f1) return 0;
        if(f2) return 0;
        return 1;
    }
public:
    int rotatedDigits(int n)
    {
        int cnt = 0;
        for (int i = 2; i <= n; i++)
        {
            cnt += plindrome((i));
        }
        return cnt;
    }
};
