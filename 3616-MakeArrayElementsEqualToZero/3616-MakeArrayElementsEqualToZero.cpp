// Last updated: 6/10/2026, 11:41:50 AM
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<int> zeros;
        for(int i = 0 ; i < n;i ++)
            if(!nums[i]) zeros.push_back(i);
            for(int i = 1; i < n;i++)   nums[i]+=nums[i-1];
            while(zeros.size()){
                int idx = zeros.back();
                int p1 = nums[idx];
                int p2 = nums[n-1] - p1;
                if(p1 == p2) ans+=2;
                else if(abs(p2-p1) == 1) ans+=1;
                zeros.pop_back();
            }    
        return ans;
    }
};