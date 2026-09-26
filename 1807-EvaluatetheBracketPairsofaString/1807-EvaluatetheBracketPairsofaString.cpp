// Last updated: 9/26/2026, 11:12:06 AM
1/* صلِّ على النبي */
2#include <bits/stdc++.h>
3
4#include <ext/pb_ds/assoc_container.hpp>
5using namespace __gnu_pbds;
6using namespace std;
7#define ll long long
8#define sz(s) (int)(s).size()
9#define all(s) s.begin(), s.end()
10
11
12class Solution {
13public:
14    string evaluate(string s, vector<vector<string>>& knowledge) {
15        unordered_map<string,string> mp;
16        for(auto record:knowledge)
17            mp[record[0]] = record[1];
18        string remaining = "";
19        string ans ="";
20        for(int i = 0 ; i < s.size() ; i++){
21            if(s[i] == '('){
22
23                ans+=remaining;
24                int j;
25                string key;
26                for( j = i+1; j < s.size(); j++){
27                    if(s[j] == ')') break;
28                    key+=s[j];
29                }
30                i=j;
31                if(mp.find(key)!=mp.end())
32                    ans+=mp[key];
33                else
34                    ans+="?";
35                remaining="";
36            }
37            else 
38                remaining+=s[i];
39        }
40        ans+=remaining;
41        return ans;
42    }
43};