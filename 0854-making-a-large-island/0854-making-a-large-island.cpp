class UnionFind {
private:
    vector<int> size, parent;
    int count;

public:
    UnionFind(int s) {
        count = 0;
        size.resize(s, 0);
        parent.resize(s, -1);
    }

    void addIsland(int x) {
        if (parent[x] >= 0)
            return;
        parent[x] = x;
        count++;
        size[x] = 1;
    }

    bool isLand(int x) {
        if (parent[x] >= 0)
            return true;
        return false;
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    int getSize(int x) {
        return size[x];
    }
    void join(int x, int y) {
        int xpat = find(x), ypat = find(y);

        if (xpat == ypat)
            return;
        else if (size[xpat] >= size[ypat]) {
            parent[ypat] = xpat;
            size[xpat] += size[ypat];
        } else if (size[xpat] < size[ypat]) {
            parent[xpat] = ypat;
            size[ypat] += size[xpat];
        }
    }
};

class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        UnionFind dsu(n * m);

        int ans = 0;
        bool f = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int pos = i * m + j;
                    dsu.addIsland(pos);

                    for (int k = 0; k < 4; k++) {
                        int nr = i + dx[k];
                        int nc = j + dy[k];
                        int neighbour = nr * m + nc;
                        if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                            dsu.isLand(neighbour)) {
                            dsu.join(pos, neighbour);
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                set<int> s;
                if (grid[i][j] == 0) {
                    int pos = i * m + j;
                    // dsu.addLand(pos);

                    for (int k = 0; k < 4; k++) {
                        int nr = i + dx[k];
                        int nc = j + dy[k];
                        int neighbour = nr * m + nc;
                        if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                            dsu.isLand(neighbour)) {
                                s.insert(dsu.find(neighbour));
                        }
                    }
                    int cnt = 1;
                    for(int pos : s) {
                        cnt += dsu.getSize(pos);
                    }

                    ans = max(ans, cnt);
                    s.clear();
                }
            }
        }
        if (ans==0) return n*m;
        return ans;
    }
};