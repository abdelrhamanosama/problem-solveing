// Last updated: 9/20/2026, 2:10:15 AM
1class Solution {
2public:
3    bool checkOverlap(int radius, int xCenter, int yCenter,
4                      int x1, int y1, int x2, int y2) {
5
6        int closestX = max(x1, min(xCenter, x2));
7        int closestY = max(y1, min(yCenter, y2));
8        vector<int>x  = {x1 , x2 , xCenter};
9        vector<int>y  = {y1 , y2 , yCenter};
10        sort(x.begin() ,x.end());
11        sort(y.begin() ,y.end());
12        // cout<<closestX<<" "<<closestY;
13        closestX = x[1];
14        closestY = y[1];
15        int dx = closestX - xCenter;
16        int dy = closestY - yCenter;
17
18        return dx * dx + dy * dy <= radius * radius;
19    }
20};