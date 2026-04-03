/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> m;
        Node* res = dfs(node, m);
        return res;
    }
private:
    Node* dfs(Node* root, map<Node*, Node*>& m) {
        if (root == nullptr)
            return nullptr;
        if (m.count(root)) {
            return m[root];
        }
        Node* tmp = new Node(root->val);
        m[root] = tmp;

        for (auto n : root->neighbors) {
            tmp->neighbors.push_back(dfs(n, m));
        }
        return tmp;
    }
};
