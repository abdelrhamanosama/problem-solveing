// Last updated: 6/10/2026, 11:46:42 AM
class Solution {
public:
    int n;
    string s;
    map<int , pair<int,int>>mp;
    int mem[27][26][2][2][301];
    int cost(int a , int b){
        auto x = mp[a];
        auto y = mp[b];
        return abs(x.first-y.first) + abs(x.second -y.second);
    }
    int dp(int f1 , int f2 , bool use1 , bool use2 , int i){
        if(i >= n) return 0;
        int &ret = mem[f1][f2][use1][use2][i];
        if(~ret) return ret;
        ret = 1e9;
        int x = s[i]-'A';
        if(use1)
            {
            ret =  dp(x,f2,1,use2,i+1)+cost(f1 , x);
                
            }
        else {
            ret = dp(x,f2,1,use2,i+1);
        }
        if(use2){
            ret = min(ret, dp(f1,x,use1,1,i+1)+cost(f2,x));
        }
        else {
            ret = min(ret, dp(f1,x,use1,1,i+1));

        }
        return ret;
    }
    int minimumDistance(string word) {
        memset(mem , -1 , sizeof mem);
        n = word.size();
        s = word;
        mp['A'-'A'] = {0,0};
        mp['B'-'A'] = {0,1};
        mp['C'-'A'] = {0,2};
        mp['D'-'A'] = {0,3};
        mp['E'-'A'] = {0,4};
        mp['F'-'A'] = {0,5};
        mp['G'-'A'] = {1,0};
        mp['H'-'A'] = {1,1};
        mp['I'-'A'] = {1,2};
        mp['J'-'A'] = {1,3};
        mp['K'-'A'] = {1,4};
        mp['L'-'A'] = {1,5};
        mp['M'-'A'] = {2,0};
        mp['N'-'A'] = {2,1};
        mp['O'-'A'] = {2,2};
        mp['P'-'A'] = {2,3};
        mp['Q'-'A'] = {2,4};
        mp['R'-'A'] = {2,5};
        mp['S'-'A'] = {3,0};
        mp['T'-'A'] = {3,1};
        mp['U'-'A'] = {3,2};
        mp['V'-'A'] = {3,3};
        mp['W'-'A'] = {3,4};
        mp['X'-'A'] = {3,5};
        mp['Y'-'A'] = {4,0};
        mp['Z'-'A'] = {4,1};

        return dp(0,0,0,0,0);

        
    }
};