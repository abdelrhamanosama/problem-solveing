// Last updated: 6/10/2026, 11:48:00 AM
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<int> distance(n+5,1e9);
    vector<pair<int,int>>v[n+5];
    for(auto x : times){
        int u = x[0] , z = x[1] , c = x[2];
        v[u].push_back({c,z}); 
    }
    priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> pq;        
    pq.push({0,k});
    distance[k] = 0;
    while(!pq.empty()){
        auto[cost, node] = pq.top(); pq.pop();
        for(auto [c,x] : v[node]){
            if(distance[node] + c < distance[x]) {
                distance[x] = c + distance[node];
                pq.push({distance[x] , x});
            }
        }
    }
    int mx = 0;
    for(int i = 1; i <= n; i++) {
        if(distance[i] == 1e9) return -1;
        mx = max(mx , distance[i]);
    }
    return mx;
}
};