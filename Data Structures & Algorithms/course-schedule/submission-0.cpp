class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis1(numCourses, false), vis2(numCourses, false);
        vector<vector<int>> adj(numCourses), radj(numCourses);
        for (auto p : prerequisites) {
            int u = p[0], v = p[1];
            adj[v].push_back(u);
            radj[u].push_back(v);
        }
        vector<int> order;
        for (int i = 0; i < numCourses; i++) {
            if (!vis1[i]) {
                dfs1(i, adj, vis1, order);
            }
        }
        for (int i = numCourses - 1; i >= 0; i--) {
            if (!vis2[order[i]]) {
                vector<int> comp;
                dfs2(order[i], radj, vis2, comp);
                if (comp.size() > 1) {
                    return false;
                }
                for (auto v : radj[comp[0]]) {
                    if (v == comp[0])
                        return false;
                }
            }
        }
        return true;

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
    void dfs2(int u, vector<vector<int>>& radj, vector<bool>& vis, vector<int>& comp) {
        vis[u] = true;
        comp.push_back(u);
        for (auto v : radj[u]) {
            if (!vis[v]) {
                dfs2(v, radj, vis, comp);
            }
        }
    }
};
