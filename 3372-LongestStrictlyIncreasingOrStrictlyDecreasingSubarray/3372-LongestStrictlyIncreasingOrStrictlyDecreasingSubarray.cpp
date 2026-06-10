// Last updated: 6/10/2026, 11:42:03 AM
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
    int maxx = -1, counter = 0;
    for(int i = 0; i < nums.size()-1;i++){
        if(nums[i+1] > nums[i]){
            if(counter)
                counter++;
            else
                counter+=2;
        }
        else{
            maxx = max(maxx,counter);
            // cout<<maxx<<" ";
            counter = 0;
        }
    }
    maxx = max(maxx,counter);
    counter = 0;
    for(int i = 0; i < nums.size()-1;i++){
        if(nums[i+1] < nums[i]){
            if(counter)
                counter++;
            else
                counter+=2;
        }
        else{
            maxx = max(maxx,counter);
            // cout<<maxx<<" ";
            counter = 0;
        }
    }
    maxx = max(maxx,counter);
    return maxx!=0? maxx:1;
}
};