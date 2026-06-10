// Last updated: 6/10/2026, 11:50:25 AM
class Solution
{
private:
// اللهم اهدنا يا رب اليك

public:
    int maxProfit(vector<int>& prices) {
        int mx = prices[prices.size() -1], ans = 0;   
        for(int i = prices.size() -2 ; i >= 0; i--){
            if(mx  > prices[i]) ans = max(ans , mx - prices[i]);
            else mx = prices[i];
        } 
        return ans;
    }
};