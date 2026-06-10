// Last updated: 6/10/2026, 11:44:45 AM
class Solution {
public:
    bool check(vector<int>& nums) {
       int l = 0 , r = 0 ,r2 = 1015 , l2 = 0;
       for(int i = 0 ; i < nums.size() ; i++){
        if(r <= nums[i])    {
            r = nums[i];
            l = i;
        }
        if(r2 > nums[i]){
            r2 = nums[i];
            l2 = i;
        }
       }



    
       cout<<l<<"\t"<<l2<<"\n";
       vector<int> v;
       for(int i = l+1; i < nums.size(); i++) v.push_back(nums[i]);
       for(auto x:v) cout<<x<<"\t";
        cout<<"\n";
       for(int i = 0 ; i <= l; i++) v.push_back(nums[i]);
       for(auto x:v) cout<<x<<"\t";
       if (is_sorted(v.begin() , v.end())) return 1;

       vector<int> v2;
       for(int i = l2 ; i < nums.size();i++) v2.push_back(nums[i]);
       for(int i = 0; i < l2 ; i++) v2.push_back(nums[i]);
       if (is_sorted(v2.begin() , v2.end())) return 1;
        return 0;
    }
};