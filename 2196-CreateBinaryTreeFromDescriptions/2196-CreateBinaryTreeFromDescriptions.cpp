// Last updated: 6/10/2026, 4:09:35 PM
1class Solution
2{
3    // struct TreeNode {
4    //     int val;
5    //     TreeNode *left;
6    //     TreeNode *right;
7    //     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8    //     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9    //     TreeNode(int x, TreeNode *left, TreeNode *right)
10    //         : val(x), left(left), right(right) {}
11    // };
12
13private:
14
15public:
16TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
17        unordered_map<int, TreeNode*> tree;
18        unordered_set<int> childern;
19        for(auto desc : descriptions){
20            int p = desc[0];
21            int child = desc[1];
22            int left = desc[2];
23            if(tree.find(p ) == tree.end())
24              tree[p] = new TreeNode(p);
25            if(tree.find(child) == tree.end())
26              tree[child] = new TreeNode(child);
27            if(left){
28                tree[p]->left = tree[child];
29            }
30            else {
31                tree[p]->right = tree[child];
32
33            }
34            childern.insert(child);
35        }
36        for(auto x:tree){
37          auto val = x.first;
38          auto root = x.second;
39          if(childern.find(val) == childern.end()){
40              return root;
41          }
42        }
43        return nullptr;
44    }
45};