// Last updated: 9/6/2026, 2:17:31 PM
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans(A.size() , 0);
        map<int,int> mp;
        for(int i = 0 ; i < A.size(); i++){
            mp[A[i]]++;
            if(mp[A[i]] == 2){
                ans[i] ++;
            }
            mp[B[i]]++;
            if(mp[B[i]] == 2){
                ans[i] ++;
            }
            if(i > 0) ans[i]+=ans[i-1];
        }
        return ans;
    }
};