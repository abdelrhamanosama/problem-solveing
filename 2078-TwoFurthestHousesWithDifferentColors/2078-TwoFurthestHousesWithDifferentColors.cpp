// Last updated: 9/6/2026, 2:19:36 PM
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int mx = 0 , n = colors.size();
        for(int i = 0 ; i < n; i++){
            if(colors[i] != colors[0]) mx = max(mx  ,i);
            if(colors[i] != colors[n-1]) mx = max(mx , n-1-i);
        }
        return mx; 
    }
};