// Last updated: 6/10/2026, 11:42:06 AM
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int freq[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, maxValue = 0;
    for(int i = 0, j = 0; j < s.size(); j++ ){
        if(++freq[s[j]-'a'] > 2)
        while(freq[s[j]-'a'] > 2)
            freq[s[i++]-'a']--;
        maxValue = max(maxValue, j-i+1); 
    }
    return maxValue;
    }
};