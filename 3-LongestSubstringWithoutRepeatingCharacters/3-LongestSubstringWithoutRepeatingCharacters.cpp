// Last updated: 6/10/2026, 11:51:30 AM
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // string s; cin>>s;
    int n = s.size();
    set<char> x;
    int mx = 0; 
    for(int i = 0 , j = 0; i < n;  i++){
        if(x.find(s[i]) == x.end()){
            x.insert(s[i]);
        }
        else{
            while(x.find(s[i]) != x.end()){
                x.erase(s[j]);
                j++;
            }
            x.insert(s[i]);
        }
        int len = i-j+1;
        mx = max(mx , len);
    }
    cout<<mx;
    return mx;
    }
};