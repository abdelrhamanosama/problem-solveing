// Last updated: 9/6/2026, 2:21:46 PM
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