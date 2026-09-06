// Last updated: 9/6/2026, 2:15:24 PM
class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        map<int,int> freq;
        multiset<pair<int,int>>top , rest;
        long long top_sum = 0;
        vector<long long> ans;
        auto balance = [&](){
            while(!rest.empty() && top.size() < x){
                auto f2 =  *prev(rest.end());
                top_sum += 1LL * f2.first * f2.second;
                rest.erase(f2);
                top.insert(f2);
            }
            while(!top.empty() && top.size() > x){
                auto f2 =  *top.begin();
                top_sum -= 1LL * f2.first * f2.second;
                rest.insert(f2);
                top.erase(f2);
            }
            while(!rest.empty() && !top.empty() && *prev(rest.end()) > *top.begin()) {
                auto f1 = *top.begin() ,f2 =  *prev(rest.end());
                top_sum -= 1LL * f1.first * f1.second;
                top_sum += 1LL * f2.first * f2.second;
                rest.erase(f2);
                top.erase(f1);
                rest.insert(f1);
                top.insert(f2);
            }
        };
        auto add = [&](int val){
            pair<int,int> xy = {freq[val],val};
            if(top.find(xy)!=top.end()){
                top_sum -= 1LL * xy.first * xy.second;
                top.erase(xy);
            }
            else if(rest.find(xy)!= rest.end()){
                rest.erase(xy);
            }
            freq[val]++;
            xy.first++;
            rest.insert(xy);
            balance();
        };
        auto remove = [&](int val){
            pair<int,int> xy = {freq[val],val};
            if(top.find(xy)!=top.end()){
                top_sum -= 1LL * xy.first * xy.second;
                top.erase(xy);
            }
            else if(rest.find(xy)!= rest.end()){
                rest.erase(xy);
            }
            freq[val]--;
            xy.first--;
            if(freq[val])
                rest.insert(xy);
            else 
                freq.erase(val);
            balance();
        };
        for(int i = 0; i < k ; i++){
            add(nums[i]);
        }
        ans.push_back(top_sum);
        for(int i = k ; i < n; i++){
            remove(nums[i-k]);
            add(nums[i]);
            balance();
            ans.push_back(top_sum);
        } 
        return ans;
    }
};