// Last updated: 6/10/2026, 11:50:34 AM
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> l(n,0) , r (n,0);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()]>= heights[i])st.pop();
            l[i] = st.empty()? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()]>= heights[i])st.pop();
            r[i] = st.empty()? n : st.top();
            st.push(i);
        }
        int mx = 0;
        for(int i = 0 ; i < n; i++){
            int w = (r[i]-l[i])-1;
            mx = max(mx,  w*heights[i]);
        }
        return mx;
    }
};