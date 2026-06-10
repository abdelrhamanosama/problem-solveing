// Last updated: 6/10/2026, 11:49:46 AM
class Solution
{
private:
// اللهم اهدنا يا رب اليك

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // topological sort 

        vector<int>adj[numCourses];
        vector<int> indeg(numCourses , 0) , topo;
        queue<int> q;
        for(auto x: prerequisites){
            int a = x[0] , b  = x[1];
            adj[b].push_back(a);
            indeg[a]++;
        }
        for(int i = 0 ; i < numCourses ; i++) if(indeg[i] == 0) q.push(i);
        while(!q.empty()){
            auto x = q.front(); q.pop();
            topo.push_back(x);
            for(auto y:adj[x]){
                if(--indeg[y] == 0) 
                    q.push(y);
            }
        }
        return topo.size() == numCourses;
    }
};