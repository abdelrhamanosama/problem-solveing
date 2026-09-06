// Last updated: 9/6/2026, 2:15:10 PM
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