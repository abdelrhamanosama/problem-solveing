// Last updated: 9/20/2026, 2:21:32 AM
1class Solution {
2        long long distance(int ux, int uy, int vx, int vy) {
3        return (long long)pow(ux - vx, 2) + (long long)pow(uy - vy, 2);
4    }
5public:
6    bool checkOverlap(int radius, int xCenter, int yCenter,
7                      int x1, int y1, int x2, int y2) {
8
9        if(x1 <= xCenter && xCenter <= x2 &&
10           y1 <= yCenter && yCenter <= y2)
11            return true;
12
13        long long R = 1LL * radius * radius;
14
15        // y = y1
16        long long dy = y1 - yCenter;
17        if(dy * dy <= R) {
18            long long dx = sqrtl(R - dy * dy);
19
20            long long px1 = xCenter + dx;
21            long long px2 = xCenter - dx;
22            cout<<px1<<" "<<px2<<"\n";
23            if((x1 <= px1 && px1 <= x2) ||
24               (x1 <= px2 && px2 <= x2))
25                return true;
26        }
27
28        // y = y2
29        dy = y2 - yCenter;
30        if(dy * dy <= R) {
31            long long dx = sqrtl(R - dy * dy);
32
33            long long px1 = xCenter + dx;
34            long long px2 = xCenter - dx;
35            cout<<px1<<" "<<px2<<"\n";
36            if((x1 <= px1 && px1 <= x2) ||
37               (x1 <= px2 && px2 <= x2))
38                return true;
39        }
40
41        // x = x1
42        long long dx = x1 - xCenter;
43        if(dx * dx <= R) {
44            long long dy2 = sqrtl(R - dx * dx);
45
46            long long py1 = yCenter + dy2;
47            long long py2 = yCenter - dy2;
48
49            if((y1 <= py1 && py1 <= y2) ||
50               (y1 <= py2 && py2 <= y2))
51                return true;
52        }
53
54        // x = x2
55        dx = x2 - xCenter;
56        if(dx * dx <= R) {
57            long long dy2 = sqrtl(R - dx * dx);
58
59            long long py1 = yCenter + dy2;
60            long long py2 = yCenter - dy2;
61
62            if((y1 <= py1 && py1 <= y2) ||
63               (y1 <= py2 && py2 <= y2))
64                return true;
65        }
66
67        /* The upper-left corner of the rectangle */
68        if (distance(xCenter, yCenter, x1, y2) <= radius * radius) {
69            return true;
70        }
71        /* The lower-left corner of the rectangle */
72        if (distance(xCenter, yCenter, x1, y1) <= radius * radius) {
73            return true;
74        }
75        /* The upper-right corner of the rectangle */
76        if (distance(xCenter, yCenter, x2, y2) <= radius * radius) {
77            return true;
78        }
79        /* The lower-right corner of the rectangle */
80        if (distance(xCenter, yCenter, x2, y1) <= radius * radius) {
81            return true;
82        }        
83
84        return false;
85    }
86};