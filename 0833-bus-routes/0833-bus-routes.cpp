class Solution {
public:

    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if ( source==target ) return 0;
        int n = routes.size();
        unordered_map<int, vector<int>> routeMap;
        vector<vector<int>> adj(n, vector<int>(n,0));
        set<int> targetRoutes;
        for(int i=0; i<n;i++) {
            for(int e : routes[i]) {
                if (e == target) targetRoutes.insert(i);
                if (routeMap.find(e)!=routeMap.end()) {
                    for(int id : routeMap[e]) {
                        adj[id][i]=adj[i][id]=1;
                    }
                }
                routeMap[e].push_back(i);
            }
        }

        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<n;j++) {
        //         cout << adj[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        vector<bool> vis(n,0);

        queue<pair<int,int>> qu;

        for(int startRoute : routeMap[source]) {
            if(targetRoutes.find(startRoute) != targetRoutes.end()) return 1;
            qu.push({startRoute, 1});
            // cout << startRoute << endl;
        }

        // for(int e : targetRoutes ) {
        //     cout << e << " ";
        // } cout << endl;
        
        while(!qu.empty()) {
            int currentRoute = qu.front().first ; 
            int hop = qu.front().second; 
            qu.pop();

            for(int i = 0;i<n;i++) {
                if (adj[currentRoute][i]==1 && !vis[i]) {
                    if (targetRoutes.find(i)!= targetRoutes.end()) return hop+1; 
                    qu.push({i, hop+1});
                    vis[i]=1;
                }
            }
        }

        return -1;

    }
};


/*
routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]],
source = 15, target = 12

7 -> 0
12 -> 0
4 -> 1
5 -> 1
15 -> 1
6 -> 2
15 -> 3


routes = [[1,2,7],[3,6,7]], source = 1, target = 6

1 -> 0
2 -> 0
7 -> 0,1
3 -> 1
6 -> 1


*/