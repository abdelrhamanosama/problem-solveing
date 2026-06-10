// Last updated: 6/10/2026, 11:48:02 AM
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n,0);
        stack<pair<int,int>> st;
        for(int i = n-1 ; i >= 0; i--){
            if(st.empty()) {
                st.push({temperatures[i],i});
                ans[i] = 0;
                continue;
            }
            else{
                while(st.top().first<=temperatures[i]) {
                    st.pop();
                    // cout<<"hi"<<i<<"\n";
                    if(st.empty()) break;
                }
                if(st.empty()) {
                    st.push({temperatures[i],i});
                    ans[i] = 0;
                    continue;
                }
                else{
                    ans[i] = abs(i - st.top().second);
                    st.push({temperatures[i],i});
                }
            }
        }
        return ans;
    }
};