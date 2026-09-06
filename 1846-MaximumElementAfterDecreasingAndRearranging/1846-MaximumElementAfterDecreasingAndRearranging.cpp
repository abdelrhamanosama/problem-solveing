// Last updated: 9/6/2026, 2:21:21 PM
class Solution {
public:
         int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
     int n = arr.size();
      vector<int>v(n+3,0);
      for(int i = 0 ; i < n; i++){
        v[min(n+1 , arr[i])]++;
      }
      int ans = 0;
      for(int i = 1 ; i <= n+1; i++){
        if(v[i] == 0) continue;
        ans = min(ans + v[i] , i); 
      }
      return ans;
    }
  
};