// Last updated: 9/6/2026, 2:26:21 PM
class Solution {
public:
#define all(s) s.begin(),s.end()

    int countNegatives(vector<vector<int>>& grid) {
       int cnt = 0;
       for(int i = 0 ; i < grid.size(); i++){
            // auto x = upper_bound(all(grid[i]) , -1)-grid[i].begin();
            // cout<<x<<"\t"<<(upper_bound(all(grid[i]) , -1)==grid[i].end())<<"\n";
            cnt +=getI(grid[i]); 
       } 
       return cnt;
    }
    int getI(vector<int> x){
        int l = 0 , r = x.size()-1, cnt = x.size();
        while(l<=r){
            int m = (l+r)/2;
            if(x[m] <= -1){
                r = m -1;
                cnt = m;
            }
            else{
                l = m +1;
            }
        }
        return x.size() - cnt;
    }
};