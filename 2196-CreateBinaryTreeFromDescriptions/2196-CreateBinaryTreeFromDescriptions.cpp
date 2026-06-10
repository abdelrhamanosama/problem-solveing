// Last updated: 6/10/2026, 3:41:57 PM
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
15    void dfs(int root, TreeNode* tree,
16             unordered_map<int, vector<pair<int,int>>>& adj)
17    {
18        for(auto [node, left] : adj[root])
19        {
20            TreeNode* subtree = new TreeNode(node);
21
22            dfs(node, subtree, adj);
23
24            if(left)
25                tree->left = subtree;
26            else
27                tree->right = subtree;
28        }
29    }
30
31public:
32    TreeNode* createBinaryTree(vector<vector<int>>& descriptions)
33    {
34        unordered_map<int, vector<pair<int,int>>> adj;
35        unordered_map<int,int> indeg;
36
37        set<int> nodes;
38
39        for(auto &d : descriptions)
40        {
41            int u = d[0];
42            int v = d[1];
43            int left = d[2];
44
45            adj[u].push_back({v,left});
46
47            indeg[v]++;
48
49            nodes.insert(u);
50            nodes.insert(v);
51        }
52
53        int root = -1;
54
55        for(auto x : nodes)
56        {
57            if(indeg[x] == 0)
58            {
59                root = x;
60                break;
61            }
62        }
63
64        TreeNode* tree = new TreeNode(root);
65
66        dfs(root, tree, adj);
67
68        return tree;
69    }
70};