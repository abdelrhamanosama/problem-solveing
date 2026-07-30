// Last updated: 7/31/2026, 1:21:38 AM
1class Solution {
2public:
3    int minimumPushes(string word) {
4        int n = word.size();
5        if(n <= 8) return n;
6        map<int,int>mp;
7        for(auto x: word) mp[x-'a']++;
8        vector<int> cnt;
9        for(auto x:mp)
10            cnt.push_back(x.second);
11        sort(cnt.begin() , cnt.end());
12        // cout<<cnt.size();
13    
14        int sum = 0 , i = 0;
15        for(auto x:cnt){
16            if(i < 8)
17                sum+=x;
18            else if(i < 16)
19                sum+=(x*2);
20            else if(i<24)
21                sum+=(x*3);
22            else 
23                sum+=(x*4);
24            i++;
25            // cout<<x<<" ";
26        }
27        return sum;
28    }
29};