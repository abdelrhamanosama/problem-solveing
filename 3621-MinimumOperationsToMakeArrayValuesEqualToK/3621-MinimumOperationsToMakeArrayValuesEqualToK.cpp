// Last updated: 6/10/2026, 11:41:48 AM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int i = 0 ; i < nums.size(); i++)   mp[nums[i]]++;
        if((mp.begin()->first) < k)
            return -1;
        int cnt = 0;
        if((mp.begin()->first) == k)
            return mp.size()-1;
        return mp.size();        
    }
};