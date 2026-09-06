// Last updated: 9/6/2026, 3:58:59 PM
class Solution
{
private:
// اللهم اهدنا يا رب اليك

public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> ans(n,0);
        for(int i = n-1 ; i>=0 ; i--){
            while(!st.empty() && heights[i]>st.top()){
                ans[i]++;
                st.pop();
            }
            if(!st.empty()) ans[i]++;
            st.push(heights[i]);
        }
        return ans;
    }
};
