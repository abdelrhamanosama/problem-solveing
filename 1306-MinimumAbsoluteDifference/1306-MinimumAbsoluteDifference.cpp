// Last updated: 6/10/2026, 11:46:59 AM
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin() , arr.end());
        int mn = 1e9;
        for(int i = 1 ; i < arr.size(); i++)
            mn = min(mn , arr[i] - arr[i-1]);
        vector<vector<int> > v;
        for(int i = 1 ; i < arr.size(); i++)
            if(arr[i] - arr[i-1] == mn){
                vector<int> x;
                x.push_back(arr[i-1]);
                x.push_back(arr[i]);
                v.push_back(x);
            }
        return v;
    }
};