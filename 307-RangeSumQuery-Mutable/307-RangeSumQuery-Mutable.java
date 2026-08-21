// Last updated: 8/21/2026, 11:15:45 PM
1class NumArray {
2
3    int[] tree;
4    int[] arr;
5
6    public NumArray(int[] nums) {
7        this.tree = new int[nums.length + 1];
8        this.arr = nums.clone();
9
10        for (int i = 0; i < nums.length; i++) {
11            add(i + 1, nums[i]);
12        }
13    }
14
15    // Add delta to position index
16    private void add(int index, int delta) {
17        while (index < tree.length) {
18            tree[index] += delta;
19            index += index & -index;
20        }
21    }
22
23    public void update(int index, int val) {
24
25        int delta = val - arr[index];
26
27        arr[index] = val;
28
29        add(index + 1, delta);
30    }
31
32    // Prefix sum [0 ... idx-1]
33    private int prefixSum(int idx) {
34
35        int sum = 0;
36
37        while (idx > 0) {
38            sum += tree[idx];
39            idx -= idx & -idx;
40        }
41
42        return sum;
43    }
44
45    public int sumRange(int left, int right) {
46
47        return prefixSum(right + 1) - prefixSum(left);
48    }
49}