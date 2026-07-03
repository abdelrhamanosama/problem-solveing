// Last updated: 7/3/2026, 8:12:58 AM
1class Solution {
2public:
3    
4  int findMaxPathScore(vector<vector<int>> &edges, vector<bool> &online,
5                       long long k)
6  {
7    const int N = 5e4 + 5;
8    int n = online.size() - 1;
9    int mx = 0;
10    vector<int> indeg(n+1,0);
11    vector<pair<int, int>> adj[N];
12    for (auto x : edges)
13    {
14      auto u = x[0], v = x[1], c = x[2];
15      adj[u].push_back({v, c});
16      mx = max(mx ,c);
17      indeg[v]++;
18    }
19    vector<int> topo;
20    if (online[0] == 0 || n == 0)
21      return -1;
22    queue<int>q;
23    for(int i = 0 ; i <= n; i++){
24      if(indeg[i] == 0) q.push(i);
25    }    
26    while(!q.empty()){
27      topo.push_back(q.front());
28      int node = q.front();
29      q.pop();
30      for(auto [x,c]: adj[node])
31        {
32          if(--indeg[x] == 0) q.push(x);
33        }
34    }
35    auto check = [&](int lim)->bool{
36      vector<long long> dist(n+1 , 1e14);
37      dist[0] = 0;
38      for(int u : topo){
39        if(dist[u] == 1e14 || !online[u]) continue;
40        for(auto [v,c] : adj[u]){
41            if(c < lim) continue;
42            if(!online[v]) continue;
43            dist[v] = min(dist[v], dist[u] + c);
44        }
45      }
46      return dist[n] <= k;
47    };
48    int l = 0;
49    int r = mx;
50    int ans = -1;
51    while(l <=  r){
52      int mid = l+r >> 1;
53      if(check(mid)){
54        ans = mid;
55        l = mid +1;
56      }
57      else
58        r = mid - 1;
59    }
60      return ans;
61
62  }
63
64};