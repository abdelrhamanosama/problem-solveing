// Last updated: 6/10/2026, 11:47:24 AM
/* صلِّ على النبي */


class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q; //  multi source BFS // (x,y,cost)
        int fresh = 0 , minutes = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1)
                    fresh++;
            }
        if (fresh == 0)
            return 0;
        if (q.empty())
            return -1;
        int mx = 0;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        auto valid = [&](int x, int y) -> bool
        {
            return x >= 0 && y >= 0 && x < n && y < m;
        };
        while (!q.empty() && fresh > 0)
        {   
            int sz = q.size();
            minutes++;
           while(sz--){
            auto [px, py] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = px + dx[i];
                int ny = py + dy[i];
                if(!valid(nx,ny)) continue;
                if(grid[nx][ny] != 1) continue;
                q.push({nx,ny});
                grid[nx][ny] = 2;
                fresh--;
            }
           }
        }
        if (fresh)
            return -1;
        return minutes;
    }
};