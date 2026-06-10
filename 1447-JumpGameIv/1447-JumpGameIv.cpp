// Last updated: 6/10/2026, 11:46:39 AM
/* صلِّ على النبي */
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define sz(s) (int)(s).size()
#define all(s) s.begin(), s.end()

class Solution
{
private:
    // اللهم اهدنا يا رب اليك
public:
    int minJumps(vector<int> &arr)
    {
        map<int, vector<int>> mp;
        for(int i = 0 ; i < arr.size() ; i++){
            mp[arr[i]].push_back(i);
        }
        vector<int> distance(arr.size(), 1e9);
        vector<bool>visited(arr.size() , 0);
        queue<int> q;
        q.push(0);
        distance[0] = 0;
        while(!q.empty()){
            int x = q.front(); q.pop();
            visited[x] = 1;
            if(x == arr.size() - 1) return distance[x];
            if(x - 1 >= 0 && visited[x-1] == 0){
                if(distance[x-1] == 1e9) {
                    distance[x-1] = distance[x] + 1;
                    q.push(x-1);
                } 
                if(distance[x-1] > distance[x] + 1) 
                {
                    distance[x-1] = distance[x] + 1;
                    q.push(x-1);
                }
            }
            if(x+1 < arr.size()&&visited[x+1] == 0){
                if(distance[x+1] == 1e9) {
                    distance[x+1] = distance[x] + 1;
                    q.push(x+1);
                } 
                if(distance[x+1] > distance[x] + 1) 
                {
                    distance[x+1] = distance[x] + 1;
                    q.push(x+1);
                }
            }
            for(auto z:mp[arr[x]]){
                if(visited[z] == 1) continue;
                if(distance[z] == 1e9) {
                    distance[z] = distance[x] + 1;
                    q.push(z);
                }
                if(distance[z] > distance[x] + 1) 
                {
                    distance[z] = distance[x] + 1;
                    q.push(z);
                }
            }
            mp[arr[x]].clear();
             
        }
        return -1;
    }
};
