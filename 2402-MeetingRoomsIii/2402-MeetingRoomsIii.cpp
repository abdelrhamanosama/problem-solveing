// Last updated: 9/6/2026, 2:18:34 PM
class Solution {
public:
#define all(s) s.begin(),s.end()

int mostBooked(int n, vector<vector<int>>& meetings) {
    vector<long long> v(n,0);
    long long i = 0, time = 0 , used = 0;
    sort(all(meetings));
    priority_queue<pair<long long,int> , vector<pair<long long,int>> , greater<pair<long long,int>>>pq;
    set<int> emp;
    for(int i = 0 ; i < n; i++) emp.insert(i);
    while(i < meetings.size()){
        long long x = meetings[i][0];      
        long long y = meetings[i][1];
        if(!emp.empty()) {
            time = max(time , x);
            while(!pq.empty()&&pq.top().first <= time){
                auto [time1 , room] = pq.top(); pq.pop();
                 emp.insert(room);
            }
            pq.push({y-x+time , *emp.begin()});
            v[*emp.begin()]++;
            // cout<<*emp.begin()<<"\n";
            emp.erase(emp.begin());
            i++;
        }
        else {
            time = max(time , x);
            while(!pq.empty()&&pq.top().first <= time){
                auto [time1 , room] = pq.top(); pq.pop();
                 emp.insert(room);
            }
            if(!pq.empty()&& emp.empty()){
                auto [time1 , room] = pq.top(); pq.pop();
                time = time1;
                emp.insert(room);
            }
            pq.push({y-x+time , *emp.begin()});
            v[*emp.begin()]++;
            emp.erase(emp.begin());
            i++;
        }
    }
    // while(!pq.empty())
    int mx = 0 , idx= 0;
    for(int i = 0 ; i<  n; i++)
        {
            if(mx < v[i]){
                idx = i;
                mx = v[i];
            }
        }
    return idx;
}

};