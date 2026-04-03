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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot)
            return true;
        if (!root)
            return false;
        if (dfs(root, subRoot))
            return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
private: 
    bool dfs(TreeNode* a, TreeNode* b) {
        if (!a && !b)
            return true;
        if (a && b && a->val == b->val) {
            return dfs(a->left, b->left) && dfs(a->right, b->right);
        }
        return false;
    }
};
