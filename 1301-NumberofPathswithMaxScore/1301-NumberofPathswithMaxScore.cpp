// Last updated: 7/6/2026, 6:24:49 AM
1class Solution {
2public:
3    static const int INF = 1e9;
4    static const int MOD = 1e9 + 7;
5
6    int mem[105][105];
7    int mem2[105][105][1805];
8
9    int dx[3] = {-1,-1,0};
10    int dy[3] = {-1,0,-1};
11
12    int dp(int i,int j,vector<string>& board){
13
14        if(i < 0 || j < 0)
15            return -INF;
16
17        if(board[i][j] == 'X')
18            return -INF;
19
20        if(i == 0 && j == 0)
21            return 0;
22
23        int &ret = mem[i][j];
24        if(ret != -1)
25            return ret;
26
27        ret = -INF;
28
29        for(int k=0;k<3;k++){
30
31            int x = i + dx[k];
32            int y = j + dy[k];
33
34            if(x < 0 || y < 0)
35                continue;
36
37            if(board[x][y] == 'X')
38                continue;
39
40            char c = board[x][y];
41
42            int add = 0;
43            if(c != 'S' && c != 'E')
44                add = c - '0';
45
46            ret = max(ret, dp(x,y,board) + add);
47        }
48
49        return ret;
50    }
51
52    int dp2(int i,int j,int sum,int target,vector<string>& board){
53
54        if(i < 0 || j < 0)
55            return 0;
56
57        if(board[i][j] == 'X')
58            return 0;
59
60        if(sum > target)
61            return 0;
62
63        if(i == 0 && j == 0)
64            return sum == target;
65
66        int &ret = mem2[i][j][sum];
67        if(ret != -1)
68            return ret;
69
70        ret = 0;
71
72        for(int k=0;k<3;k++){
73
74            int x = i + dx[k];
75            int y = j + dy[k];
76
77            if(x < 0 || y < 0)
78                continue;
79
80            if(board[x][y] == 'X')
81                continue;
82
83            char c = board[x][y];
84
85            int add = 0;
86            if(c != 'S' && c != 'E')
87                add = c - '0';
88
89            ret += dp2(x,y,sum+add,target,board);
90            ret %= MOD;
91        }
92
93        return ret;
94    }
95
96    vector<int> pathsWithMaxScore(vector<string>& board) {
97
98        memset(mem,-1,sizeof(mem));
99        memset(mem2,-1,sizeof(mem2));
100
101        int n = board.size();
102
103        int mx = dp(n-1,n-1,board);
104
105        if(mx < 0)
106            return {0,0};
107
108        int cnt = dp2(n-1,n-1,0,mx,board);
109
110        return {mx,cnt};
111    }
112};