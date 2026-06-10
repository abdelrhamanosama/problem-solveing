// Last updated: 6/10/2026, 11:48:46 AM
class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word[0] < 'a'){
            if(word.size() > 1){
                if(word[1] < 'a'){
                    for(auto x:word)
                    {
                        if(x > 'Z') return 0;
                    }
                    return 1;
                }
                else{
                    word[0] = 'a';
                    for(auto x:word)
                    {
                        if(x < 'a') return 0;
                    }
                    return 1;
                }
            }
            else
                return 1;
        }   
        else{
            for(auto x:word)
             {
                if(x <'a') return 0;
             }
             return 1;
        }
    }
};