// Last updated: 6/30/2026, 5:46:37 PM
1class Solution
2{
3private:
4// اللهم اهدنا يا رب اليك
5
6public:
7    int numberOfSubstrings(string s) {
8        map<int,int> mp;
9        long long n = s.size();
10        long long ans = 0;
11        for(int i = 0 , j = 0; i < n; i++){
12            mp[s[i]]++;
13            while(mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0){
14                mp[s[j]]--;
15                j++;
16            }
17            ans += i-j+1;
18        }
19        return n*(n+1)/2 - ans;
20    }
21};
22//  n   n(n+1)/2 - ans