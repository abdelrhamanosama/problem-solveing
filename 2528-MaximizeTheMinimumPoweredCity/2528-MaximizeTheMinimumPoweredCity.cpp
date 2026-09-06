// Last updated: 9/6/2026, 2:18:06 PM
class Solution {
 public:
  long long maxPower(vector<int>& stations, int r, int k) {
    long left = *min_element(stations.begin() , stations.end()) ,
        right = accumulate(stations.begin() , stations.end(),0L) + k + 1;
    long ans = left;
    while(left < right){
        long mid  = (right+left)/2;
        bool x = check(stations , r , k , mid);
        if(x){
            left = mid+1;
            ans = mid;
        }
        else{
            right = mid;
        }
    }
    return ans;
  }

 private:
  bool check(vector<int> stations, int r, int additionalStations,
            long minPower) {
    const int n = stations.size();
    long power = accumulate(stations.begin(), stations.begin() + r, 0L);
    for(int i = 0 ; i < n ;i++){
        if(i+r < n){
            power += stations[i + r];
        }
        if(power < minPower){
            const long requiredPower = minPower - power;
            if(requiredPower > additionalStations) return 0;
            additionalStations -= requiredPower;
            power += requiredPower;
            stations[min(n - 1, i + r)] += requiredPower;
        }
        if(i-r>=0) 
            power -= stations[i - r];
    }
    return 1;
  }
};