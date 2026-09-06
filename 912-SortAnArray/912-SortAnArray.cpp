// Last updated: 9/6/2026, 4:00:50 PM
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        map<int,int>freq;
        vector<int> ans;
        for(int i = 0 ; i < nums.size(); i++)
            freq[nums[i]]++;
        for(auto &i : freq)
            {
                int cnt = i.second;
                while(cnt){
                    ans.push_back(i.first);
                    cnt--;
                }
            }
        return ans;
    }
};