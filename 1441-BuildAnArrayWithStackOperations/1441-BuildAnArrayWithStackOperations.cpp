// Last updated: 9/6/2026, 2:24:33 PM
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ops;
        int j = 0; // pointer in target
        
        for (int i = 1; i <= n && j < target.size(); i++) {
            ops.push_back("Push");
            if (i == target[j]) {
                j++; // number matches target
            } else {
                ops.push_back("Pop"); // remove it
            }
        }
        return ops;
    }
};
