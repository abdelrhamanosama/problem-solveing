// Last updated: 6/10/2026, 11:47:56 AM
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // sort by end ascending, then start descending
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if(a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });

        int a = -1, b = -1; // last two chosen points
        int ans = 0;

        for(auto &in : intervals){
            int l = in[0], r = in[1];

            bool aIn = (a >= l && a <= r);
            bool bIn = (b >= l && b <= r);

            if(aIn && bIn){
                continue; // already have 2 points inside interval
            }
            else if(bIn){
                // only one point inside → need one more
                ans++;
                a = b;
                b = r;
            }
            else {
                // zero points inside → need 2 new points
                ans += 2;
                a = r - 1;
                b = r;
            }
        }

        return ans;
    }
};
