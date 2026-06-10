// Last updated: 6/10/2026, 11:48:37 AM
class Solution {
public:
int findLHS(vector<int> &nums)
{
    map<int , int> map ;
    int i = 0, f1, f2, size = 0, maxValue = 0;
    for(int i = 0; i < nums.size(); i++) {
        map[nums[i]]++;
    }
    if(map.size() == 1) return 0;
     for (const auto& pair : map) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    for (const auto& pair : map) {
        f2 = f1;
        f1 = pair.first; 
        if(i++>0){
           if((int)abs(f1 - f2) == 1)
                size = map[f1] + map[f2];
        }
        maxValue = max(maxValue,size);
        cout<<"f1" <<f1<<endl;
    }
    return maxValue;
}
};