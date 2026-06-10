// Last updated: 6/10/2026, 11:47:02 AM
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size()  < 3) return false;
    for (int i = 0; i <= arr.size()-3; i++)
    {
        if(arr[i] % 2 == 1 && arr[i+1]%2== 1 && arr[i+2]%2 == 1)
            {
                return true;
            }
    }
    return false;
            
}
};