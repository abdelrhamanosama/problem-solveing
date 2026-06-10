// Last updated: 6/10/2026, 11:45:48 AM
class Solution {
public:
    int countOdds(int low, int high) {
        //
        if(low %2 == 0 && high%2 == 0) return (high-low)/2;
        else if(low % 2 == 0 && high%2 == 1) return (high-low-1)/2 + 1;
        else if(low% 2 == 1 && high %2 == 0) return (high-(low+1))/2 + 1;
        else return (high-low-1-1)/2 + 2;
    }
};