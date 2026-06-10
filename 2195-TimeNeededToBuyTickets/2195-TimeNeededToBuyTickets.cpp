// Last updated: 6/10/2026, 11:43:27 AM
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        deque<pair<int,bool>> dq;
        for(int i  = 0 ; i <tickets.size(); i++){
            if(i == k){
                dq.push_back({tickets[i] , 1});
            }
            else{
                dq.push_back({tickets[i] , 0});
            }
        }
        int ans = 0;
        
        while(1){
            ans++;
            int y = dq.front().first;
            int x = dq.front().second;
            if(y == 1 && x == 1) return ans;
            y--;
            if(y > 0)
            dq.push_back({y,x});
            dq.pop_front();
        }
        return ans;
    }
};