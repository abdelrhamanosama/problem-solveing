// Last updated: 9/6/2026, 2:17:26 PM
class Solution {
public:
  struct dsu
  {
    vector<int> p , s ,edges;
    set<int> ss;
    dsu(int n){
      edges = vector<int> (n , 0);
      s = vector<int> (n , 1);
      p = vector<int> (n , 1);
      for(int i = 0; i < n; i++){
        p[i] = i;
        ss.insert(i);
      }
    }
    int find(int u){
      if(u==p[u]) return u;
      return p[u] = find(p[u]); 
    }
    void merge(int u , int v){
      int l1 = find(u);
      int l2 = find(v);
      
      if(l1 == l2) {
        edges[l1]++;
        return;
      }
      if(l1 > l2) swap(l1 , l2);
      p[l2] = l1;
      s[l1]+=s[l2];
      ss.erase(l2);
      edges[l1]+=edges[l2]+1;
    }
    int calc(int leader){
      int cnt1 = s[leader];
      if(cnt1 == 1) return 1;
      int cnt2 = cnt1*(cnt1-1)/2;
      int cnt3 = edges[leader];
      cout<<cnt2 <<" "<< cnt3<<"\n";
      return cnt3 == cnt2;
    }
  };
  
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        dsu d(n);
        for(auto x:edges){
          int u = x[0] , v = x[1];
          d.merge(u,v);
        }
        int sum = 0;
        for(auto x:d.ss){
          sum+=d.calc(x);
        }
      return sum;
    }
};