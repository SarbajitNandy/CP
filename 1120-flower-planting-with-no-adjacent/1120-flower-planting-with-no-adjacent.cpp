class Solution {
    void fillDfs(int cur,vector<vector<int>> &adj,vector<int> &vis,
                            vector<int> &color)
    {
        vis[cur] = 2;
        set<int> avoidColor;
        for(int node:adj[cur]){
            if(vis[node]==2)
                continue;
            if(vis[node]==0)
                fillDfs(node,adj,vis,color);
            avoidColor.insert(color[node-1]);
        }
        for(int toFill=1;toFill<=4;toFill++){
            if(avoidColor.find(toFill)==avoidColor.end()){
                color[cur-1] = toFill;
                break;
            }
        }
        vis[cur] = 1;
    }
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n+1);
        for(auto &ele:paths){
            adj[ele[0]].push_back(ele[1]);
            adj[ele[1]].push_back(ele[0]);
        }
        vector<int> color(n,0);
        vector<int> vis(n+1,0);
        for(int i=1;i<=n;i++){
            if(vis[i]==0)
                fillDfs(i,adj,vis,color);
        }
        return color;
    }
};