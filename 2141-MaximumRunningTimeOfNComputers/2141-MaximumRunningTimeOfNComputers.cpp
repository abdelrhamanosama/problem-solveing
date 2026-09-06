// Last updated: 9/6/2026, 2:19:06 PM
class Solution {
public:
    bool check(long long t , vector<int> b, long long n){
        vector<long long> v(n);
        long long i = b.size()-1, j = n-1;
        for( ; i>=0; i--){
            v[j] = b[i];
            j--;
            if(j < 0) break;
        }
        if(i <= 0){
            if(t <= v[0]) return 1;
            else return 0;
        }
        else{
            // cout<<t<<"\t"<<i<<"\n";
            if(t <= v[0]) return 1;
            long long sum = 0;
            for(long long k = 0 ; k < i; k++)
                {
                    sum+=b[k];
                }
            for(j = n-1; j>=0; j--){
                long long time = 0;
                if(t <= v[j]) continue;
                if(sum +v[j] < t) return 0;
                else {
                    time = abs(t-(sum + v[j]));
                    sum -= (t-v[j]);
                }
            }
            return 1;
        }
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin() , batteries.end());
        long long l = 0 ,r = 1e14 , ans = 0;
        while(r>=l){
            long long mid = (l+r)/2;
            if(check(mid , batteries , n)){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return ans;
    }
};