// Last updated: 9/6/2026, 4:03:45 PM
class NumArray {

    int[] tree;
    int[] arr;

    public NumArray(int[] nums) {
        this.tree = new int[nums.length + 1];
        this.arr = nums.clone();

        for (int i = 0; i < nums.length; i++) {
            add(i + 1, nums[i]);
        }
    }

    // Add delta to position index
    private void add(int index, int delta) {
        while (index < tree.length) {
            tree[index] += delta;
            index += index & -index;
        }
    }

    public void update(int index, int val) {

        int delta = val - arr[index];

        arr[index] = val;

        add(index + 1, delta);
    }

    // Prefix sum [0 ... idx-1]
    private int prefixSum(int idx) {

        int sum = 0;

        while (idx > 0) {
            sum += tree[idx];
            idx -= idx & -idx;
        }

        return sum;
    }

    public int sumRange(int left, int right) {

        return prefixSum(right + 1) - prefixSum(left);
    }
}