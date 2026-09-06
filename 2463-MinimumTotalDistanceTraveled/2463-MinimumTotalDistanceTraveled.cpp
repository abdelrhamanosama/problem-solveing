// Last updated: 9/6/2026, 2:18:18 PM
class Solution {

    long long mem[101][101][101];

    vector<int> robot;
    vector<vector<int>> factory;

    long long dp(int i , int j , int used){

        if(i == robot.size())
            return 0;

        if(j == factory.size())
            return 1e15;

        long long &ret = mem[i][j][used];

        if(ret != -1)
            return ret;

        ret = dp(i , j+1 , 0);

        if(used < factory[j][1]){

            long long cost =
                abs(robot[i] - factory[j][0]) +
                dp(i+1 , j , used+1);

            ret = min(ret , cost);
        }

        return ret;
    }

public:

    long long minimumTotalDistance(vector<int>& r,
                                   vector<vector<int>>& f) {

        robot = r;
        factory = f;

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        memset(mem , -1 , sizeof mem);

        return dp(0 , 0 , 0);
    }
};