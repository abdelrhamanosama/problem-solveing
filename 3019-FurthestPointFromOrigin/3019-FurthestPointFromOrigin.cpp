// Last updated: 6/10/2026, 11:42:16 AM
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int suml = 0 , sumr = 0;
        // case  of l 
        for(auto x:moves){
            if(x == 'R') suml--;
            else suml++;
            if(x == 'L') sumr--;
            else sumr++;
        }
        
        return max((suml) , (sumr));
    }
};