// Last updated: 7/12/2026, 8:45:53 AM
1class Solution {
2public:
3  struct dsu
4  {
5    vector<int> p , s ,edges;
6    set<int> ss;
7    dsu(int n){
8      edges = vector<int> (n , 0);
9      s = vector<int> (n , 1);
10      p = vector<int> (n , 1);
11      for(int i = 0; i < n; i++){
12        p[i] = i;
13        ss.insert(i);
14      }
15    }
16    int find(int u){
17      if(u==p[u]) return u;
18      return p[u] = find(p[u]); 
19    }
20    void merge(int u , int v){
21      int l1 = find(u);
22      int l2 = find(v);
23      
24      if(l1 == l2) {
25        edges[l1]++;
26        return;
27      }
28      if(l1 > l2) swap(l1 , l2);
29      p[l2] = l1;
30      s[l1]+=s[l2];
31      ss.erase(l2);
32      edges[l1]+=edges[l2]+1;
33    }
34    int calc(int leader){
35      int cnt1 = s[leader];
36      if(cnt1 == 1) return 1;
37      int cnt2 = cnt1*(cnt1-1)/2;
38      int cnt3 = edges[leader];
39      cout<<cnt2 <<" "<< cnt3<<"\n";
40      return cnt3 == cnt2;
41    }
42  };
43  
44    int countCompleteComponents(int n, vector<vector<int>>& edges) {
45        dsu d(n);
46        for(auto x:edges){
47          int u = x[0] , v = x[1];
48          d.merge(u,v);
49        }
50        int sum = 0;
51        for(auto x:d.ss){
52          sum+=d.calc(x);
53        }
54      return sum;
55    }
56};