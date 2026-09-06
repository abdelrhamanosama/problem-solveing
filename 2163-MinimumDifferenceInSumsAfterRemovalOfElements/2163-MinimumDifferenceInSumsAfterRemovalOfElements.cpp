// Last updated: 9/6/2026, 2:19:02 PM
/* صلِّ على النبي */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        vector<long long>l(3*n+1,0),r(3*n+1,0);
        priority_queue<int>mx;
        priority_queue<int, vector<int> ,greater<int>>mn;
        long long suml = 0 , sumr = 0;
        for(int i = 0 ; i< n*2; i++){
            suml+=nums[i];
            mx.push(nums[i]);
            if(mx.size() > n) {
                suml-=mx.top();
                mx.pop();
            }
            if(mx.size() == n){
                l[i] = suml;
            }
        }


        for(int i = n*3-1 ; i>= n; i--){
            sumr+=nums[i];
            mn.push(nums[i]);
            if(mn.size() > n) {
                sumr-=mn.top();
                mn.pop();
            }
            if(mn.size() == n){
                r[i] = sumr;
            }
        }
        long long mno = 1e13;
       for(int i = n-1 ; i< n*2; i++){
            cout<<mno <<" "<< l[i] <<" "<<r[i]<<"\n";
            mno = min(mno , l[i]-r[i+1]);
       }
       return mno;
    }

};