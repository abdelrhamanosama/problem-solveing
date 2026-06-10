// Last updated: 6/10/2026, 11:41:38 AM
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
    // نسخة sorted by X
    vector<vector<int>> px = buildings;
    sort(px.begin(), px.end(), [](auto &a, auto &b){
        if(a[0] != b[0]) return a[0] < b[0];
        return a[1] < b[1];
    });

    // نسخة sorted by Y
    vector<vector<int>> py = buildings;
    sort(py.begin(), py.end(), [](auto &a, auto &b){
        if(a[1] != b[1]) return a[1] < b[1];
        return a[0] < b[0];
    });

    int cnt = 0;

    for(auto &b : buildings){
        int x = b[0], y = b[1];

        // بحث على X
        auto rangeX = equal_range(px.begin(), px.end(), b,
                                  [](const vector<int>& a, const vector<int>& b){
                                      return a[0] < b[0];
                                  });
        auto it = lower_bound(rangeX.first, rangeX.second, y,
                      [](const vector<int>& a, int val){
                          return a[1] < val; // مقارنة على y فقط
                      });

        bool coveredX = ((it != rangeX.second) &&(it != (rangeX.second -1))  && (it != rangeX.first));

        // بحث على Y
        auto rangeY = equal_range(py.begin(), py.end(), b,
                                  [](const vector<int>& a, const vector<int>& b){
                                      return a[1] < b[1];
                                  });
        it = lower_bound(rangeY.first, rangeY.second, x,
                      [](const vector<int>& a, int val){
                          return a[0] < val; // مقارنة على y فقط
                      });
        bool coveredY = ((it != rangeY.second)&& (it != (rangeY.second-1)) && (it != rangeY.first));

        if(coveredX && coveredY) cnt++;
        // cout<<cnt << "\t"<< x<<"\t"<<y<<"\n"; 
    }

    return cnt;
}
};