// Last updated: 10/20/2026, 6:30:53 PM
1class Solution {
2public:
3    int sortableIntegers(vector<int>& nums) {
4        vector<int>  div;
5        int n = nums.size();
6        int sum = 0;
7        for(int i = 1;i*i<=n; i++){
8            if(n%i == 0){
9                div.push_back(i);
10                if(n/i != i) 
11                    div.push_back(n/i);
12            }
13        }
14        vector<int> nums2 = nums;
15        sort(nums2.begin() , nums2.end());
16        auto check =[](vector<int> &nums1 ,vector<int>& nums2)->bool{
17            int L = nums1.size();
18            for(int i  = 0 ; i + 1 < L; i++){
19                if(nums1[i] > nums1[i+1]){
20                    vector<int> cycled;
21                    cycled.insert(cycled.end() , nums1.begin()+i+1,nums1.end());
22                    cycled.insert(cycled.end() , nums1.begin(),nums1.begin()+i+1);
23                    return nums2==cycled;
24                }
25            }
26            return nums1 == nums2;
27        };
28        for(auto x:div){
29            bool flag = 1;
30            for(int i = 0 ; i<n; i+=x){
31                vector<int> sub1,sub2;
32                sub1.insert(sub1.end() ,nums.begin()+i, nums.begin()+i+x);
33                sub2.insert(sub2.end() ,nums2.begin()+i, nums2.begin()+i+x);
34                if(!check(sub1,sub2)){
35                    flag = 0;
36                    break;
37                }
38            }
39            if(flag) sum+=x;
40        }
41        return sum;
42    }
43};