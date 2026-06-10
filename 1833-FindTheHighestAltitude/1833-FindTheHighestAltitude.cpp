// Last updated: 6/10/2026, 11:44:51 AM
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0 , mx = 0;
        for(int i  : gain) 
        {
            sum += i;
            mx = max(mx , sum);
        }  
        return mx;
    }
};