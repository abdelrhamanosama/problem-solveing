// Last updated: 6/10/2026, 11:48:52 AM
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

class Solution {
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

public:



typedef tree<long long , null_type, less_equal<long long >, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int reversePairs(vector<int>& nums) {
    ordered_set os;
    long long  ans = 0;
    for(int i = nums.size()-1; i >= 0; i--){
        ans += os.order_of_key(nums[i]); 
        // cout<<ans<<"\n";
        os.insert((long long)nums[i]*2ll); 
    }
    return ans;
}

};