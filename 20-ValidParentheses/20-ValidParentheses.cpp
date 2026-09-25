// Last updated: 9/25/2026, 8:01:28 AM
1class Solution {
2    unordered_map<TreeNode*, long long> mp;
3    TreeNode* mainRoot;
4
5    long long dfs1(TreeNode* root) {
6        if (root == nullptr)
7            return 0;
8
9        long long sum = root->val
10                      + dfs1(root->left)
11                      + dfs1(root->right);
12
13        mp[root] = sum;
14
15        return sum;
16    }
17
18    void dfs2(TreeNode* root, long long& mx) {
19        if (root == nullptr)
20            return;
21
22        dfs2(root->left,mx);
23        dfs2(root->right,mx);
24
25        long long sub = mp[root];
26        long long other = mp[mainRoot] - sub;
27
28        mx = max(mx, sub * other);
29    }
30
31public:
32    int maxProduct(TreeNode* root) {
33        mainRoot = root;
34
35        dfs1(root);
36
37        long long mx = 0;
38        dfs2(root, mx);
39
40        return mx % 1'000'000'007;
41    }
42};