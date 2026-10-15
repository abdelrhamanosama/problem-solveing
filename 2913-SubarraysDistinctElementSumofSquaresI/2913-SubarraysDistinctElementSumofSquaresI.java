// Last updated: 10/15/2026, 3:04:56 PM
1import java.util.List;
2import java.util.HashSet;
3import java.util.Set;
4class Solution {
5    public int sumCounts(List<Integer> nums) {
6        int res = 0;
7        for(int i = 0 ; i < nums.size(); i++){
8            Set<Integer> set = new HashSet<>();
9            for(int j = i;j < nums.size();j++)
10                {
11                    set.add(nums.get(j));
12                    res += (set.size()*set.size());
13                }
14        }
15        return res;
16    }
17}