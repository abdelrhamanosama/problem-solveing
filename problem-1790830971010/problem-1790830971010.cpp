// Last updated: 10/1/2026, 8:02:51 AM
1class Solution {
2public:
3    vector<vector<string>> groupAnagrams(vector<string>& strs) {
4        unordered_map<string,string> mp1; 
5        unordered_map<string,int> mp2;
6        int idx = 0;
7        for(auto x: strs){
8            auto y = x;
9            sort(y.begin() , y.end());
10            mp1[x] = y;
11            // cout<<y<<"\n";
12            if(mp2.find(y) == mp2.end()){
13                mp2[y] = idx++;
14            }
15        }
16        vector<vector<string>> ans(idx);
17        // cout<<mp1.size()<<"\n";
18        // cout<<mp2.size()<<"\n";
19        for(auto x:strs){
20            ans[mp2[mp1[x]]].push_back(x);
21        }
22        return ans;
23    }
24};