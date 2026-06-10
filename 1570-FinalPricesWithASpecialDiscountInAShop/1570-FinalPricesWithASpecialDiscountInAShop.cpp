// Last updated: 6/10/2026, 11:45:57 AM
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i = n-1 ; i >= 0; i--){
            if(st.empty()) {
                st.push(prices[i]);
                ans[i] = prices[i];
                continue;
            }
            else{
                while(st.top()>prices[i]) {
                    st.pop();
                    if(st.empty()) break;
                }
                if(st.empty()) {
                    st.push(prices[i]);
                    ans[i] = prices[i];
                    continue;
                }
                else{
                    ans[i] = prices[i] - st.top();
                    st.push(prices[i]);
                }
            }
        }
        return ans;
    }
};