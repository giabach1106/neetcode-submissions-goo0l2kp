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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> tmp;

            int t = q.size();
            while (t--) {
                TreeNode* Val = q.front();
                q.pop();
                if (Val) {
                    tmp.push_back(Val->val);
                    if (Val->left)
                        q.push(Val->left);
                    if (Val->right)
                        q.push(Val->right);
                }
            }
            if (!tmp.empty()) 
                res.push_back(tmp);

        }
        return res;
    }
};
