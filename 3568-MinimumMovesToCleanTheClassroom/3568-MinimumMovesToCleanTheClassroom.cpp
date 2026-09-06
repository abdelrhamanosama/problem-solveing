// Last updated: 9/6/2026, 2:13:55 PM
class Solution {
public:

    int n, m;
    int fullMask;
    int maxEnergy;

    int id[20][20];

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    struct State {
        int x, y;
        int mask;
        int energy;
    };

    int minMoves(vector<string>& classroom, int energy) {

        n = classroom.size();
        m = classroom[0].size();
        maxEnergy = energy;

        memset(id, -1, sizeof(id));

        int cnt = 0;
        int sx = 0, sy = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }

                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
            }
        }

        fullMask = (1 << cnt) - 1;

        int masks = 1 << cnt;

        // visited[x][y][mask][energy]
        int totalStates = n * m * masks * (energy + 1);

        vector<bool> visited(totalStates, false);

        auto getId = [&](int x, int y, int mask, int e) {
            return (((x * m + y) * masks + mask) * (energy + 1) + e);
        };

        queue<State> q;

        visited[getId(sx, sy, 0, energy)] = true;

        q.push({sx, sy, 0, energy});

        int moves = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                State cur = q.front();
                q.pop();

                int x = cur.x;
                int y = cur.y;
                int mask = cur.mask;
                int e = cur.energy;

                if (mask == fullMask) {
                    return moves;
                }

                if (e == 0) {
                    continue;
                }

                for (int d = 0; d < 4; d++) {

                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx < 0 || nx >= n ||
                        ny < 0 || ny >= m) {
                        continue;
                    }

                    if (classroom[nx][ny] == 'X') {
                        continue;
                    }

                    int ne = e - 1;
                    int nmask = mask;

                    // Clean trash
                    if (classroom[nx][ny] == 'L') {
                        nmask |= (1 << id[nx][ny]);
                    }

                    // Recharge
                    if (classroom[nx][ny] == 'R') {
                        ne = maxEnergy;
                    }

                    int stateId = getId(nx, ny, nmask, ne);

                    if (visited[stateId]) {
                        continue;
                    }

                    visited[stateId] = true;

                    q.push({
                        nx,
                        ny,
                        nmask,
                        ne
                    });
                }
            }

            moves++;
        }

        return -1;
    }
};