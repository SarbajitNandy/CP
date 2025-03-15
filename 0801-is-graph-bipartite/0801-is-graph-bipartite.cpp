class Solution {
public:
    bool dfs(int id, vector<vector<int>>& graph, vector<int>& vis) {
        for (int v : graph[id]) {
            if (vis[v] == -1) {
                vis[v] = !vis[id];
                if (dfs(v, graph, vis) == false) return false;
            } else if (vis[v] == vis[id])
                return false;
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();

        vector<int> vis(v, -1);

        for (int i = 0; i < v; i++) {

            if (vis[i] == -1) {
                vis[i] = 0;
                if (dfs(i, graph, vis)==false) return false;
            }
        }

        return true;
    }
};