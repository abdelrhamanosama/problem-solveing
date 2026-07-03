// Last updated: 7/3/2026, 8:11:48 AM
1class Solution {
2public:
3    
4  int findMaxPathScore(vector<vector<int>> &edges, vector<bool> &online,
5                       long long k)
6  {
7    const int N = 5e4 + 5;
8    int n = online.size() - 1;
9    vector<int> indeg(n+1,0);
10    vector<pair<int, int>> adj[N];
11    for (auto x : edges)
12    {
13      auto u = x[0], v = x[1], c = x[2];
14      adj[u].push_back({v, c});
15      indeg[v]++;
16    }
17    vector<int> topo;
18    if (online[0] == 0 || n == 0)
19      return -1;
20    queue<int>q;
21    for(int i = 0 ; i <= n; i++){
22      if(indeg[i] == 0) q.push(i);
23    }    
24    while(!q.empty()){
25      topo.push_back(q.front());
26      int node = q.front();
27      q.pop();
28      for(auto [x,c]: adj[node])
29        {
30          if(--indeg[x] == 0) q.push(x);
31        }
32    }
33    auto check = [&](int lim)->bool{
34      vector<long long> dist(n+1 , 1e14);
35      dist[0] = 0;
36      for(int u : topo){
37        if(dist[u] == 1e14 || !online[u]) continue;
38        for(auto [v,c] : adj[u]){
39            if(c < lim) continue;
40            if(!online[v]) continue;
41            dist[v] = min(dist[v], dist[u] + c);
42        }
43      }
44      return dist[n] <= k;
45    };
46    int l = 0;
47    int r = 1e9;
48    int ans = -1;
49    while(l <=  r){
50      int mid = l+r >> 1;
51      if(check(mid)){
52        ans = mid;
53        l = mid +1;
54      }
55      else
56        r = mid - 1;
57    }
58      return ans;
59
60  }
61
62};