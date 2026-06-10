// Last updated: 6/10/2026, 11:51:07 AM
class Solution
{
private:

    void backtrack(int n, string &s , vector<string> &v , int open , int close){
        if(open  == n && close == n){
                v.push_back(s);
            return;
        }
        if(open < n)
            {
                s+='(';
            backtrack(n, s ,v , open + 1 ,close);
            s.pop_back();
            }
        if(close < open)
            {
                s+=')';
            backtrack(n, s ,v, open ,close+ 1);
            s.pop_back();
            }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string s;
        backtrack(n,s,v,0,0);
        // vector<string> x;
        // for(auto y:v) x.push_back(y);
        return v;       
    }
};