// Last updated: 9/6/2026, 2:20:12 PM
#define all(s) s.begin(), s.end()
class Solution
{
public:
    int minOperations(vector<vector<int>> &grid, int x)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> v;
        for(int i =  0 ; i < n; i++)
            for(int j = 0; j < m;j++) 
                v.push_back(grid[i][j]);
        int rem = v[0]%x;
        for(auto y: v) if(y%x != rem) return -1;
        sort(all(v));
        int median = v[v.size()/2];
        int cnt = 0;
        for(int i= 0 ; i< v.size(); i++)
            cnt += abs(median - v[i])/x;
        return cnt;
    }
};
