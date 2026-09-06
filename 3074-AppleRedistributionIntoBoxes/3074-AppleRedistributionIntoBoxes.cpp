// Last updated: 9/6/2026, 2:16:09 PM
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = 0;
        for(auto x : apple) sum += x;
        sort(capacity.begin() , capacity.end());
        int cnt = 0;
        for(int i = capacity.size()-1; i>= 0 ; i--)
            {
                sum -= capacity[i];
                cnt ++;
                if(sum <= 0) 
                    return cnt;

            }
                    return cnt;

    }
};