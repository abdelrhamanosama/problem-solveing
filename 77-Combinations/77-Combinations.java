// Last updated: 8/12/2026, 2:36:39 AM
1import java.util.ArrayList;
2import java.util.List;
3
4class Solution {
5
6    private void backtrack(
7            int start,
8            int n,
9            int k,
10            List<Integer> current,
11            List<List<Integer>> result) {
12
13        if (current.size() == k) {
14            result.add(new ArrayList<>(current));
15            return;
16        }
17
18        for (int i = start; i <= n; i++) {
19            current.add(i);
20
21            backtrack(
22                i + 1,
23                n,
24                k,
25                current,
26                result
27            );
28
29            current.remove(current.size() - 1);
30        }
31    }
32
33    public List<List<Integer>> combine(int n, int k) {
34
35        List<List<Integer>> result = new ArrayList<>();
36        List<Integer> current = new ArrayList<>();
37
38        backtrack(1, n, k, current, result);
39
40        return result;
41    }
42}