class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();

        vector<int> vis(v, -1);

        for (int i = 0; i < v; i++) {
            queue<int> q;

            if (vis[i] == -1) {
                vis[i] = 0;
                q.push(i);

                while (!q.empty()) {
                    int top = q.front();
                    q.pop();
                    int nextColor = vis[top] == 1 ? 0 : 1;
                    for (int v : graph[top]) {
                        if (vis[v] == -1) {
                            vis[v] = nextColor;
                            q.push(v);
                        } else if (vis[v] != nextColor)
                            return false;
                    }
                }
            }
        }

        return true;
    }
};