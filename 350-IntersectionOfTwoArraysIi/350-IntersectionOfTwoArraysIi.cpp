// Last updated: 6/10/2026, 11:49:14 AM
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int freq[1001];
        vector<int>v;
        for (int i = 0; i < nums1.size(); i++) {
            freq[nums1[i]]++;
        }
        for(int i = 0; i < nums2.size();i++)  {
                if(freq[nums2[i]]>0) {v.push_back(nums2[i]);freq[nums2[i]]--;}
        }
        return v;
    }
};