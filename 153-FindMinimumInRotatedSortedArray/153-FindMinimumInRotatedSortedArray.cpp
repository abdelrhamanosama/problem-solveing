// Last updated: 6/10/2026, 11:50:11 AM
class Solution {
private:
    int doo(int l, int r, vector<int>& nums) {
        if (l == r)
            return nums[l];

        int mid = (l + r) / 2;

        int opt1 = doo(l, mid, nums);
        int opt2 = doo(mid + 1, r, nums);

        return min(opt1, opt2);
    }

public:
    int findMin(vector<int>& nums) {
        return doo(0, nums.size() - 1, nums);
    }
};