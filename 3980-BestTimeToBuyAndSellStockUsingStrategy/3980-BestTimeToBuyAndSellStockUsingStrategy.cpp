// Last updated: 6/10/2026, 11:41:22 AM
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long  sum = 0, mx = -1e12, n = prices.size();
        vector<int>xx(n,0);
        for(int i = 0 ; i < n; i++)
            sum +=prices[i]*strategy[i];
        mx = max(mx, sum);
        sum = 0; 
        for(int i = 0 ; i < k; i++){
            if(i >= k/2){
                sum += prices[i];
                xx[i] = 1;
            }
        }
        for(int i = k ; i < n; i++){
            sum+=prices[i]*strategy[i];
        }
        mx = max(mx, sum);
        cout<<mx<<"\n";
        for(int i = k ; i < n ; i++){
            if(xx[i-k])
                {
                    sum -= prices[i-k];
                    sum += prices[i-k]*strategy[i-k];
                    // cout<<"hi\t"<<i<<"\n";
                }
            else{
                sum += prices[i-k]*strategy[i-k];   
                // cout<<"bye\t"<<i-k<<"\n";
            }
            sum -= prices[i-k/2];
            xx[i-k/2] = 0;
            sum-=prices[i]*strategy[i];
            sum += prices[i];
            mx = max(mx , sum);
            // sum += prices[i-k/2]*strategy[i-k/2];
        // cout<<mx<<"\n";

        }
        return mx;
    }
    

};