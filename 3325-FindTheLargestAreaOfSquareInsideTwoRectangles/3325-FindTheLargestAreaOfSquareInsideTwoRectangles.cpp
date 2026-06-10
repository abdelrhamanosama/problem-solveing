// Last updated: 6/10/2026, 11:42:10 AM
class Solution {
#define sz(s) (int)(s).size()

public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long maxSide = 0;
        for(int i = 0 ; i < sz(bottomLeft); i++){
            int x1 = bottomLeft[i][0];
            int y1 = bottomLeft[i][1];
            int x2 = topRight[i][0];
            int y2 = topRight[i][1];
            for(int j = i+1; j < sz(bottomLeft); j++){

                int x3 = bottomLeft[j][0];
                int y3 = bottomLeft[j][1];
                int x4 = topRight[j][0];
                int y4 = topRight[j][1];
                long long w = min(y4,y2) - max(y3,y1);
                long long h = min(x4,x2) - max(x3,x1);
                maxSide = max( maxSide , min(w,h));
            }
        }
        return maxSide*maxSide;
    }
};