// Last updated: 9/7/2026, 11:45:42 PM
1class Solution {
2public:
3    bool canConstruct(string ransomNote, string magazine) {
4        int freq[26] = { };
5        for(int i = 0; i < magazine.size(); i++)
6            freq[magazine[i]-'a']++;
7        for(int i = 0; i < ransomNote.size(); i++){
8            if(freq[ransomNote[i]-'a'] <1) return false;
9            freq[ransomNote[i]-'a']--;
10        }
11        return true;
12    }
13};