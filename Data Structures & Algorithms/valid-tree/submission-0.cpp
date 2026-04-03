class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1)
            return false;
        vector<vector<int>> adj(n);
        for (auto e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis);
            }
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                return false;
        }
        return true;
    }
private:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[u] = true;
        for (auto v : adj[u]) {
            if (!vis[v]) {
                dfs(v, adj, vis);
            }
        }
    }
};
