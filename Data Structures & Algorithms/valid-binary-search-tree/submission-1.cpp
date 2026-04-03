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
    bool isValidBST(TreeNode* root) {
        queue<tuple<TreeNode*, int, int>> q;    
        q.push({root, INT_MIN, INT_MAX});
        while (!q.empty()) {
            auto [tmp, left, right] = q.front();
            q.pop();
            if (!(left < tmp->val and tmp->val < right))
                return false;
            if (tmp->left)  
                q.push({tmp->left, left, tmp->val});
            if (tmp->right)
                q.push({tmp->right, tmp->val, right});
        }
        return true;
    }
};
