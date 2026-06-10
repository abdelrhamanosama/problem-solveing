// Last updated: 6/10/2026, 11:42:57 AM
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        while(1){
            if(binary_search(nums.begin() , nums.end() , original))
                {
                    original *= 2;
                }
            else{
                return original;
            }
        }   
    }
};