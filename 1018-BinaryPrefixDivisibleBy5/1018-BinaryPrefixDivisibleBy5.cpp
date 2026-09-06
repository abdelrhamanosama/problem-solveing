// Last updated: 9/6/2026, 4:00:16 PM
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> answer;
        int prefix = 0;
        int length = nums.size();
        for (int i = 0; i < length; i++) {
            prefix = ((prefix << 1) + nums[i]) % 5;
            answer.emplace_back(prefix == 0);
        }
        return answer;
    }
};