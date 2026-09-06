// Last updated: 9/6/2026, 2:16:51 PM
class Solution {
public:
int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
    vector<long long> value;
    for(auto x: values) value.push_back(x);
    set<int> v[n];
    map<int,int>lines ;
    for(auto x: edges){
        int a = x[0] , b = x[1];
        v[a].insert(b);
        v[b].insert(a);
        lines[a]++;
        lines[b]++;
    }
    int cnt = 0;
    auto fun =[&]{
    vector<int>del;
    for(auto &x:lines)
        {
            if(x.second <= 1)
                {   
                    int a = x.first;
                    int b = *v[x.first].begin();
                    if(value[a] % k == 0) {
                        cnt++;
                    }
                    else{
                       value[b]+=value[a]; 
                    }
                    // values[a] = -1;  
                    del.push_back(a);
                    n--;
                }
        }
        for(auto x:del)
            {
                int b = *v[x].begin();
                v[x].erase(b);
                v[b].erase(x);
                lines.erase(x);
                lines[b]--;
            }
    };
    if(edges.empty()){
        for(int i = 0 ; i < n; i++)
            cnt+=(value[i]%k == 0);
        return cnt;
    }
    while(n > 0)
        {
            fun();
        }
    return cnt;
}
};