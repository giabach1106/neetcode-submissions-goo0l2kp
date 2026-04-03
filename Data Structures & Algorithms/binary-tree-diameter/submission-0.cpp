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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        dfs(res, root);
        return res;
    }
private: 
    int dfs(int& res, TreeNode* root) {
        if (!root)
            return 0;
        int maxL = dfs(res, root->left);
        int maxR = dfs(res, root->right);
        res = max(res, maxL + maxR);
        return 1 + max(maxL, maxR);
    }
};
