// Last updated: 6/10/2026, 11:48:13 AM
class Solution {
public:
    bool judgeCircle(string moves) {
        int r,l,u,d;
        r=l=u=d=0;
        for(auto x:moves)
            if(x == 'U')u++;
            else if(x == 'D')d++;
            else if(x == 'R')r++;
            else l++;
    return (u-d == 0)&&(r-l == 0);
    }
};