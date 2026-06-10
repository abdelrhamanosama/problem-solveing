// Last updated: 6/10/2026, 11:42:23 AM
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        map<int,int>mp;
        set<int>st1,st2;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            st1.insert(nums[i]);
        }
        int k = st1.size();
        int cnt = 0;
        int last = 0;
        for(int i = 0, j = 0; i < n; i++) 
            {
                mp[nums[i]]++;
                if(mp.size() == k){
                        
                        while(mp.size()==k){
                            cnt+=n-i;
                            mp[nums[j]]--;
                            if(!mp[nums[j]]){
                                mp.erase(nums[j]);
                            }
                            j++;
                        }
                    // last = i;
                }
            }
        return cnt;
    }
};