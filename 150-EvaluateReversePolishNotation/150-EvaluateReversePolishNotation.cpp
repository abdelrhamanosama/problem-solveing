// Last updated: 6/10/2026, 11:50:14 AM
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for (auto &t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                int res = 0;
                
                if (t == "+") res = a + b;
                else if (t == "-") res = a - b;
                else if (t == "*") res = a * b;
                else if (t == "/") res = a / b;
                
                st.push(res);
            } else {
                st.push(stoi(t));
            }
        }
        
        return st.top();
    }
};
