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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector <int> m,n;
        dfs(p, m);
        dfs(q, n);
        if (m.size() != n.size())
            return false;
        else {
            for (int i = 0; i < m.size(); i++) {
                if (m[i] != n[i])
                    return false;
            }
            return true;
        }
    }
private: 
    void dfs (TreeNode* p, vector<int>& ans) {
        if (p) {
            ans.push_back(p->val);
            if (p->left)
                dfs (p->left, ans);
            else {
                ans.push_back(-1);
            }
            if (p->right)
                dfs (p->right, ans);
            else {
                ans.push_back(-1);
            }
        }
    }
};
