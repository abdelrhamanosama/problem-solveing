// Last updated: 6/10/2026, 11:43:33 AM
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
    vector<vector<int>> g(n + 1);
    for (auto &e : edges) {
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
    }

    // dist[u] يخزن أقل ساعتين للوصول لـ u
    vector<vector<long long>> dist(n + 1);

    // BFS queue: {node, currentTime}
    queue<pair<int,long long>> q;
    q.push({1, 0});
    dist[1].push_back(0);

    while (!q.empty()) {
        auto [u, curTime] = q.front(); q.pop();

        for (auto v : g[u]) {
            long long nextTime = curTime;

            // احسب الانتظار عند الإشارة
            if ((nextTime / change) % 2 == 1) { // إذا في إشارة حمراء
                nextTime = (nextTime / change + 1) * change;
            }

            nextTime += time; // أضف زمن الطريق

            // أضف الوقت فقط إذا مختلف عن الموجودين وليس أكثر من اثنين
            if ((dist[v].empty() || nextTime != dist[v][0]) &&
                dist[v].size() < 2) {
                dist[v].push_back(nextTime);
                q.push({v, nextTime});
            }
        }
    }

    // dist[n][1] هو الوقت الثاني الأقل للوصول لـ n
    return dist[n][1];
}
};