class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int res = 0;
        vector<vector<int>> adj(n);   
        for (auto e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis1(n, false), vis2(n, false);
        vector<int> order;
        for (int i = 0; i < n; i++) {
            if (!vis1[i]) {
                dfs1(i, adj, vis1, order);
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (!vis2[order[i]]) {
                res++;
                dfs2(order[i], adj, vis2);
            }
        }
        return res;
    }
private:
    void dfs1(int u, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& order) {
        vis[u] = true;
        for (auto v : adj[u]) {
            if (!vis[v]) {
                dfs1(v, adj, vis, order);
            }
        }
        order.push_back(u);
    }
    void dfs2(int u, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[u] = true;
        for (auto v : adj[u]) {
            if (!vis[v]) {
                dfs2(v, adj, vis);
            }
        }
    }
    
};