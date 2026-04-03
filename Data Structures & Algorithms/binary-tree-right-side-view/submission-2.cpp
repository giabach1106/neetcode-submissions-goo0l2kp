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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;    
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int t = q.size();
            TreeNode* right = nullptr;
            while (t--) {
                TreeNode* tmp = q.front();
                q.pop();
                if (tmp) {
                    right = tmp;
                    if (tmp->left)
                        q.push(tmp->left);
                    if (tmp->right)
                        q.push(tmp->right);
                }
            }
            if (right)
                res.push_back(right->val);
        }
        return res;
    }
};
