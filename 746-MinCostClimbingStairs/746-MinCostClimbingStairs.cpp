// Last updated: 9/6/2026, 4:01:38 PM
class Solution {
    int mem[1005];
    vector<int> cost;
    int n;
public:
    int minCostClimbingStairs(vector<int>& c) {
        memset(mem, -1 , sizeof mem);
        cost = c;
        n = c.size();
        int opt1 = dp(0);
        memset(mem, -1 , sizeof mem);
        opt1 = min(opt1  ,dp(1));
        return opt1;
    }
    int dp(int idx){
        if(idx >= n) return 0;
        if(~mem[idx]) return mem[idx];
        int opt1 = 1e9, opt2 = 1e9;
        opt1 = dp(idx + 1) + cost[idx];
        opt2 = dp(idx + 2) + cost[idx];
        return mem[idx] = min(opt1,opt2);
    }
};