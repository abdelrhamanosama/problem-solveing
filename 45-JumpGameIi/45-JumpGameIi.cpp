// Last updated: 6/10/2026, 11:50:57 AM
class Solution {
public:
    int jump(vector<int>& nums) {
       int n = nums.size(); 
       if (n <= 1) return 0;
       int jumps = 0;
       int endo = 0 , f = 0;
       for(int i = 0 ; i < n;i++ ){
            f= max(f , i+nums[i]);
            if(endo == i)
            {
                jumps++;
                endo =f;
                if(endo >= n-1) return jumps;
            }
            
       } 
       return jumps;
    }
};