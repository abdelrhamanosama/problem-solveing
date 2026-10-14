// Last updated: 10/14/2026, 6:03:39 PM
1class Solution {
2public:
3    string maxSumOfSquares(int num, int sum) {
4        if(sum < 10) {
5            string res = to_string(sum);
6            res.append(num - (int)res.size(), '0');
7            return res;
8        }
9        else  if(sum > 9*num){ return "";}
10        else {
11            int r = sum % 9;
12        string ans(sum / 9, '9');
13        if (r > 0) {
14            ans.push_back('0' + r);
15        }
16        ans.append(num - (int)ans.size(), '0');
17        return ans;
18        }
19    }
20};