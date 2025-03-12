class Solution {
private:
    vector<int> topoSort(int n, vector<vector<int>> adj) {
        vector<int> inD(n, 0);

        for (int i = 0; i < n; i++) {
            for (int v : adj[i]) {
                inD[v]++;
            }
        }

        queue<int> q;
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (inD[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int front = q.front();
            q.pop();

            ans.push_back(front);

            for (int v : adj[front]) {
                inD[v]--;

                if (inD[v] == 0)
                    q.push(v);
            }
        }

        // return vector<int>(ans.rbegin(), ans.rend());
        return ans;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());

        for(auto e: prerequisites) {
            adj[e[1]].push_back(e[0]);
        }

        auto res = topoSort(numCourses, adj);
        if(res.size()!= numCourses) return {};
        return res;
    }
};