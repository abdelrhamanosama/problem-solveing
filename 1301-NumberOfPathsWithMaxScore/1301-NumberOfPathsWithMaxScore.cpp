// Last updated: 9/6/2026, 3:59:47 PM
class Solution {
public:
    static const int INF = 1e9;
    static const int MOD = 1e9 + 7;

    int mem[105][105];
    int mem2[105][105][1805];

    int dx[3] = {-1,-1,0};
    int dy[3] = {-1,0,-1};

    int dp(int i,int j,vector<string>& board){

        if(i < 0 || j < 0)
            return -INF;

        if(board[i][j] == 'X')
            return -INF;

        if(i == 0 && j == 0)
            return 0;

        int &ret = mem[i][j];
        if(ret != -1)
            return ret;

        ret = -INF;

        for(int k=0;k<3;k++){

            int x = i + dx[k];
            int y = j + dy[k];

            if(x < 0 || y < 0)
                continue;

            if(board[x][y] == 'X')
                continue;

            char c = board[x][y];

            int add = 0;
            if(c != 'S' && c != 'E')
                add = c - '0';

            ret = max(ret, dp(x,y,board) + add);
        }

        return ret;
    }

    int dp2(int i,int j,int sum,int target,vector<string>& board){

        if(i < 0 || j < 0)
            return 0;

        if(board[i][j] == 'X')
            return 0;

        if(sum > target)
            return 0;

        if(i == 0 && j == 0)
            return sum == target;

        int &ret = mem2[i][j][sum];
        if(ret != -1)
            return ret;

        ret = 0;

        for(int k=0;k<3;k++){

            int x = i + dx[k];
            int y = j + dy[k];

            if(x < 0 || y < 0)
                continue;

            if(board[x][y] == 'X')
                continue;

            char c = board[x][y];

            int add = 0;
            if(c != 'S' && c != 'E')
                add = c - '0';

            ret += dp2(x,y,sum+add,target,board);
            ret %= MOD;
        }

        return ret;
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {

        memset(mem,-1,sizeof(mem));
        memset(mem2,-1,sizeof(mem2));

        int n = board.size();

        int mx = dp(n-1,n-1,board);

        if(mx < 0)
            return {0,0};

        int cnt = dp2(n-1,n-1,0,mx,board);

        return {mx,cnt};
    }
};