// Last updated: 9/6/2026, 3:57:39 PM
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
        bool canReach(vector<int>& arr, int start) {
            queue<int> q;
            vector<bool> visited(arr.size()+3, 0);
            q.push(start);
            while(!q.empty()){
                auto x = q.front();
                q.pop();
                visited[x] = 1;
                if(arr[x] == 0) return 1;
                int y = x-arr[x];
                int z = x+arr[x];
                if(y>=0 && !visited[y]) 
                q.push(y);
                if(z < arr.size() && !visited[z]) 
                q.push(z);
            }
        return 0;
    }
};
