// Last updated: 10/4/2026, 12:47:19 AM
1class Solution {
2public:
3    int longestValidParentheses(auto& s) {
4        int res = 0;
5        vector<int> stack = {-1};
6        
7        for (int i = 0; i < s.size(); i++) {
8            if (s[i] == '(')
9                stack.push_back(i);
10            else {
11                stack.pop_back();
12                
13                if (stack.empty())
14                    stack.push_back(i);
15                else
16                    res = max(res, i - stack.back());
17            }
18        }
19        
20        return res;
21    }
22};