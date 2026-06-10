// Last updated: 6/10/2026, 11:42:34 AM
class Solution
{
private:
    // اللهم اهدنا يا رب اليك

public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> v;
        int n = nums.size();
        for(int i = 0 ; i <n; i++){
            int x = nums[i];
            vector<int> y;
            while(x){
                y.push_back(x%10);
                x/=10;
            }
            while(!y.empty()) {
                v.push_back(y.back());
                y.pop_back();
            }
        } 
        return v;  
    }
};