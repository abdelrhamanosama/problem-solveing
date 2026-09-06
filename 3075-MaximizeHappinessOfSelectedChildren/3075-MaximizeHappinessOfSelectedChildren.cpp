// Last updated: 9/6/2026, 2:16:03 PM
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin() , happiness.end());
        long long cnt = 0 , sum = 0;
        for(int i = happiness.size() - 1; i >= 0 && cnt < k ; i--){
            if(happiness[i] - cnt >= 0) 
                {
                    sum += (happiness[i]-cnt);
                    cnt++;
                }
            else
                break;

        }    
        return sum;
    }
};
// auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });