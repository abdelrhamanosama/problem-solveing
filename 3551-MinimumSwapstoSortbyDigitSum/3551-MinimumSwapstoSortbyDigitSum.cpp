// Last updated: 10/17/2026, 4:35:38 AM
1class Solution {
2
3    int solve(int n){
4        int sum=0;
5        while(n!=0){
6            sum+=n%10;
7            n=n/10;
8        }
9        return sum;
10    }
11
12  void helper(vector<int>&nums,vector<pair<int,int>>&temp){
13      for(int i=0;i<nums.size();i++){
14          int sum=solve(nums[i]);
15           temp.push_back({sum,nums[i]});
16      }
17  }
18    
19public:
20  int minSwaps(vector<int>& nums) {
21    vector<pair<int,int>>temp;
22    helper(nums,temp);
23    sort(temp.begin(), temp.end(),[](const pair<int,int> &a, const pair<int,int> &b) {
24        if (a.first != b.first) 
25            return a.first<b.first;  
26        return a.second<b.second;     
27    });
28
29    vector<int>a;
30    for (int i=0;i<temp.size();i++){
31        a.push_back(temp[i].second);
32    }
33    int n=nums.size();
34    unordered_map<int,int>mp2;
35    for( int i=0;i<n;i++){
36        mp2[a[i]]=i;
37    }
38    unordered_map<int,int>mp;
39      for(int i=0;i<n;i++){
40          mp[i]=mp2[nums[i]];
41      }
42    vector<bool>visited(n,false);
43    int cnt=0;
44    for (int i=0;i<n;i++){
45        if(visited[i] || mp[i]==i) continue;
46        int cycle_size=0;
47        int j=i;
48        while(!visited[j]){
49            visited[j]=true;
50            j=mp[j];
51            cycle_size++;
52        }
53        if(cycle_size>1){
54            cnt+=(cycle_size-1);
55        }
56    }
57    return cnt;
58}
59};