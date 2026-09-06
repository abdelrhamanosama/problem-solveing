// Last updated: 9/6/2026, 2:27:08 PM
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double x = (minutes/2.0)/6.0;
        double y = (hour*5)%60;
        double sum = 0;
        double mn = min(x+y,(double)minutes),mx = max(x+y,(double)minutes);
        cout<<x+y<<"\t"<<minutes<<"\n";
        return min((mx-mn)*6.0 , 360-((mx-mn)*6.0));
    }
};