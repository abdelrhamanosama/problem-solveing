// Last updated: 6/10/2026, 11:51:13 AM
class Solution {
public:
    vector<vector<string>> v = vector<vector<string>>(10);
    vector<string> s;

    void building(){
        v[2] = {"a", "b", "c"};
        v[3] = {"d", "e", "f"};
        v[4] = {"g", "h", "i"};
        v[5] = {"j", "k", "l"};
        v[6] = {"m", "n", "o"};
        v[7] = {"p", "q", "r", "s"};
        v[8] = {"t", "u", "v"};
        v[9] = {"w", "x", "y", "z"};
    }

    void backtrack(string& digits, int i, string current){
        if(i == digits.size()){
            s.push_back(current);
            return;
        }
        int digit = digits[i] - '0';
        for(string& ch : v[digit]){
            backtrack(digits, i+1, current + ch);
        }
    }

    vector<string> letterCombinations(string digits) {
        s.clear();
        if(digits.empty()) return s;
        building();
        backtrack(digits, 0, "");
        return s;
    }
};
