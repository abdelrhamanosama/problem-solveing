// Last updated: 6/10/2026, 11:50:50 AM
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       sort(intervals.begin() , intervals.end());
        vector<vector<int>> v;
        for(int i = 0 ; i < intervals.size(); i++){
            vector<int> ans;
            ans.push_back(intervals[i][0]);
            int last = intervals[i][1];
            while(i+1<intervals.size() && last >= intervals[i+1][0]){
                last = max(last , intervals[i+1][1]);
                i++;
            }
            ans.push_back(last);
            v.push_back(ans);
        } 
        return v;
    }
};