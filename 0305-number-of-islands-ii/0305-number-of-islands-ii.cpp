class UnionFind {
private:
    vector<int> rank, parent;

    int count;

public:
    UnionFind(int size) {
        rank.resize(size, 0);
        parent.resize(size, -1);
        count = 0;
    }

    void addLand(int x) {
        if (parent[x] >= 0)
            return;
        parent[x] = x;
        count++;
    }

    bool isLand(int x) {
        if (parent[x] >= 0)
            return true;
        return false;
    }

    int numberOfIsland() { return count; }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    void join(int x, int y) {
        int parx = find(x), pary = find(y);

        if (parx == pary) {
            return;
        } else {
            if (rank[parx] < rank[pary]) {
                parent[parx] = pary;
            } else if (rank[parx] > rank[pary]) {
                parent[pary] = parx;
            } else {
                rank[parx]++;
                parent[pary] = parx;
            }

            count--;
        }
    }
};

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {

        UnionFind unionFind(m * n);

        vector<int> res;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        for (auto pos : positions) {
            int row = pos[0];
            int col = pos[1];

            int landPosition = row * n + col;
            unionFind.addLand(landPosition);

            for (int k = 0; k < 4; k++) {
                int nr = row + dx[k];
                int nc = col + dy[k];
                int nlandPosition = nr * n + nc;

                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    unionFind.isLand(nlandPosition)) {
                    unionFind.join(landPosition, nlandPosition);
                }
            }
            res.push_back(unionFind.numberOfIsland());
        }

        return res;
    }
};