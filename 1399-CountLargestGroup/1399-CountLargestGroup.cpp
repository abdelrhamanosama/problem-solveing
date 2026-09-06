// Last updated: 9/6/2026, 2:25:34 PM
class Solution {
public:
    int Digits(int n){
        int sum = 0;
        while(n)    {
            sum+=n%10;
            n=n/10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        vector<int>sumOfDigits(40,0);
        map<int,int>mp;
        int mx = 0; 
        for(int i = 1 ; i <= n ;i++) {
            int d = Digits(i);
            // cout<<d<<" ";
            sumOfDigits[d]++;
        }
        for(int i = 0 ; i < 40 ; i++)
            {
                mp[sumOfDigits[i]]++;
            }
        auto it = mp.end();
        it--;
        return it->second;
    }
};