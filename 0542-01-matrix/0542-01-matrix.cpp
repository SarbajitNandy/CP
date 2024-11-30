class Solution {
public:
    typedef pair<int, int> P;

    vector<vector<int>> updateMatrix(vector<vector<int>> grid) {
        int n = grid.size(), m = grid[0].size();

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};

        queue<pair<P, int>> qu;
        vector<vector<int>> res(n, vector<int>(m, 1e9));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    // vis[i][j] = 1;
                    qu.push({{i, j}, 0});
                }
            }
        }

        while (!qu.empty()) {
            auto front = qu.front();
            qu.pop();
            int row = front.first.first;
            int col = front.first.second;
            int hop = front.second;

            if (res[row][col] > hop) {
                res[row][col] = hop;

                for (int k = 0; k < 4; k++) {
                    int nr = row + dx[k];
                    int nc = col + dy[k];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                        grid[nr][nc] == 1 && res[nr][nc] == 1e9) {
                        qu.push({{nr, nc}, hop + 1});
                        // vis[nr][nc] = 1;
                    }
                }
            }
        }

        return res;
    }
};