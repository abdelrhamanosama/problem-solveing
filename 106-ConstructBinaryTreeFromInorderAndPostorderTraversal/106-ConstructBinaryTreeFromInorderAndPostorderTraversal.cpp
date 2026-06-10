// Last updated: 6/10/2026, 11:50:31 AM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* build(
    vector<int>& inorder, int is, int ie,
    vector<int>& postorder, int ps, int pe,
    unordered_map<int,int>& pos
){
    if (is > ie || ps > pe) return NULL;

    int valRoot = postorder[pe];
    TreeNode* root = new TreeNode(valRoot);

    int k = pos[valRoot];
    int leftSize = k - is;

    root->left = build(
        inorder, is, k-1,
        postorder, ps, ps + leftSize - 1,
        pos
    );

    root->right = build(
        inorder, k+1, ie,
        postorder, ps + leftSize, pe - 1,
        pos
    );

    return root;
}


TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int,int> mp;
    for(int i = 0; i < inorder.size(); i++)
        mp[inorder[i]] = i;

    return build(
        inorder, 0, inorder.size() - 1,
        postorder, 0, postorder.size() - 1,
        mp
    );
}

};