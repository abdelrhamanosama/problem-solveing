// Last updated: 9/6/2026, 2:16:56 PM
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