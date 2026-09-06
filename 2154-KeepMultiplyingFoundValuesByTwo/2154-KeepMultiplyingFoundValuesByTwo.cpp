// Last updated: 9/6/2026, 2:18:58 PM
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