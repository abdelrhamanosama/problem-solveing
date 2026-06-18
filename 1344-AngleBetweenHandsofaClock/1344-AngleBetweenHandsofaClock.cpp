// Last updated: 6/18/2026, 6:21:22 PM
1class Solution {
2public:
3    double angleClock(int hour, int minutes) {
4        double x = (minutes/2.0)/6.0;
5        double y = (hour*5)%60;
6        double sum = 0;
7        double mn = min(x+y,(double)minutes),mx = max(x+y,(double)minutes);
8        cout<<x+y<<"\t"<<minutes<<"\n";
9        return min((mx-mn)*6.0 , 360-((mx-mn)*6.0));
10    }
11};