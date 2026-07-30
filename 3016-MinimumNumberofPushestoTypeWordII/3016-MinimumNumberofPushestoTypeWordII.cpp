// Last updated: 7/31/2026, 1:26:40 AM
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
12        reverse(cnt.begin() , cnt.end());
13        // cout<<cnt.size();
14    
15        int sum = 0 , i = 0;
16        for(auto x:cnt){
17            if(i < 8)
18                sum+=x;
19            else if(i < 16)
20                sum+=(x*2);
21            else if(i<24)
22                sum+=(x*3);
23            else 
24                sum+=(x*4);
25            i++;
26            cout<<x<<" ";
27        }
28        return sum;
29    }
30};