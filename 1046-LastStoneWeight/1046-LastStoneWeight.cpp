// Last updated: 9/6/2026, 4:00:13 PM
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto x:stones) pq.push(x);
        while(pq.size() > 1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if(y == x) continue;
            else pq.push(x-y);
        }
        if(pq.empty()) return 0;
        else return pq.top();
    }
};