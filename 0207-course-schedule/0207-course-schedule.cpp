class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;

        vector<int> inDegree(n, 0);
        queue<int> q;
        vector<int> adj[n];
        vector<int> ans;

        for (auto e : prerequisites) {
            adj[e[1]].push_back(e[0]);
            inDegree[e[0]]++;
        }

        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        int cnt = 0;

        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            cnt++;

            for (int adjNode : adj[top]) {

                inDegree[adjNode]--;
                if (inDegree[adjNode] < 0)
                    return false;
                else if (inDegree[adjNode] == 0)
                    q.push(adjNode);
            }
        }

        if (cnt < n)
            return false;

        return true;
    }
};