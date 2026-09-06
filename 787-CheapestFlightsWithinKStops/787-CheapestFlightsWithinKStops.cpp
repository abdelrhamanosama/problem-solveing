// Last updated: 9/6/2026, 4:01:20 PM
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);
        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        const long long INF = 1e18;
        // dist[node][edges] = أقل تكلفة للوصول لـ node باستخدام edges حواف
        vector<vector<long long>> dist(n, vector<long long>(k + 2, INF));

        priority_queue<
            array<long long,3>,
            vector<array<long long,3>>,
            greater<array<long long,3>>
        > pq;

        dist[src][0] = 0;
        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto [cost, u, edges] = pq.top();
            pq.pop();

            if (cost != dist[u][edges]) continue;
            if (edges == k + 1) continue;

            for (auto [v, w] : adj[u]) {
                if (cost + w < dist[v][edges + 1]) {
                    dist[v][edges + 1] = cost + w;
                    pq.push({dist[v][edges + 1], v, edges + 1});
                }
            }
        }

        long long ans = INF;
        for (int e = 0; e <= k + 1; e++) {
            ans = min(ans, dist[dst][e]);
        }

        return ans == INF ? -1 : ans;
    }
};
