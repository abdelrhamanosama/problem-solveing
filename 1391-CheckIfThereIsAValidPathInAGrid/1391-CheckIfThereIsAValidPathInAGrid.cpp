// Last updated: 9/6/2026, 2:25:27 PM
struct dsu{
    vector<int> p;
    dsu(int n){
        p = vector<int>(n+1);
        for(int i = 0 ; i<= n;i++){
            p[i] = i;
        }
    }
    int find(int u){
        if(u == p[u]) return u;
        return p[u] = find(p[u]);
    }

    void merge(int u , int v){
        int l1 = find(u);
        int l2 = find(v);
        if(l1 == l2) return;
        p[l1] = l2;
    }
    bool connected(int u , int v) {
        return find(u) == find(v);
    }
};
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
       dsu d(n*m);
       for(int i = 0 ; i< n; i++){
            for(int j = 0 ; j < m; j++){
                if(grid[i][j] == 1){
                    if(j -1 >= 0&&(grid[i][j-1] == 1||grid[i][j-1] == 4 ||grid[i][j-1] == 6))
                        {
                            int u = i*m + j;
                            int v = i*m+ j-1;
                            d.merge(u,v);
                        }
                    if(j +1 < m &&(grid[i][j+1] == 1||grid[i][j+1] == 3 ||grid[i][j+1] == 5)){
                            int u = i*m + j;
                            int v = i*m+ j+1;
                            d.merge(u,v);
                    }
                }
                else if(grid[i][j] == 2){
                    if(i - 1 >= 0&&(grid[i-1][j] == 2||grid[i-1][j] == 5 ||grid[i-1][j] == 6))
                        {
                            int u = i*m + j;
                            int v = (i-1)*m+ j;
                            d.merge(u,v);
                        }
                    if(i +1 < n &&(grid[i+1][j] == 2||grid[i+1][j] == 3 ||grid[i+1][j] == 4)){
                            int u = i*m + j;
                            int v = (i+1)*m+ j;
                            d.merge(u,v);
                    }   
                }
                else if(grid[i][j] == 3){
                    if(i +1 < n &&(grid[i+1][j] == 2||grid[i+1][j] == 5 ||grid[i+1][j] == 6)){
                            int u = i*m + j;
                            int v = (i+1)*m+ j;
                            d.merge(u,v);
                    }
                    if(j -1 >= 0&&(grid[i][j-1] == 1||grid[i][j-1] == 4 ))
                        {
                            int u = i*m + j;
                            int v = i*m+ j-1;
                            d.merge(u,v);
                        }
                }
                else if(grid[i][j] == 4){
                    if(i +1 < n &&(grid[i+1][j] == 2||grid[i+1][j] == 5 ||grid[i+1][j] == 6)){
                            int u = i*m + j;
                            int v = (i+1)*m+ j;
                            d.merge(u,v);
                    }

                    if(j +1 < m &&(grid[i][j+1] == 1||grid[i][j+1] == 3)){
                            int u = i*m + j;
                            int v = i*m+ j+1;
                            d.merge(u,v);
                    }
                }
                else if(grid[i][j] == 5){
                    if(i -1 >= 0&&(grid[i-1][j] == 2||grid[i-1][j] == 3 ||grid[i-1][j] == 4))
                        {
                            int u = i*m + j;
                            int v = (i-1)*m+ j;
                            d.merge(u,v);
                        }
                    if(j -1 >= 0&&(grid[i][j-1] == 1||grid[i][j-1] == 6 ))
                        {
                            int u = i*m + j;
                            int v = i*m+ j-1;
                            d.merge(u,v);
                        }
                }
                else if(grid[i][j] == 6){
                    if(i -1 >= 0&&(grid[i-1][j] == 2||grid[i-1][j] == 3 ||grid[i-1][j] == 4))
                        {
                            int u = i*m + j;
                            int v = (i-1)*m+ j;
                            d.merge(u,v);
                        }
                        if(j +1 < m &&(grid[i][j+1] == 1||grid[i][j+1] == 5)){
                            int u = i*m + j;
                            int v = i*m+ j+1;
                            d.merge(u,v);
                    }
                }

            }
       } 
       return d.connected(0,(n-1)*(m)+(m-1));
    }
};