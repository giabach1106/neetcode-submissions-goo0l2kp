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
    int goodNodes(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        int res = 0;
        q.push({root, -INT_MAX});
        while (!q.empty()) {
            TreeNode* tmp = q.front().first;
            int maxVal = q.front().second;
            q.pop();
            if (tmp->val >= maxVal)
                res++;
            if (tmp->left)
                q.push({tmp->left, max(tmp->val, maxVal)});
            if (tmp->right)
                q.push({tmp->right, max(tmp->val, maxVal)});

        }
        return res;
    }
};
