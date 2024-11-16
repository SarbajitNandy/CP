class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;

        queue<pair<pair<int, int>, int>> qu;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    qu.push({{i, j}, 0});
                } else if (grid[i][j]==1) fresh++;
            }
        }

        int res = 0;

        while (!qu.empty()) {
            int row = qu.front().first.first;
            int col = qu.front().first.second;
            int minute = qu.front().second;
            qu.pop();

            res = max(res, minute);

            for (auto dir : dirs) {
                int nRow = row + dir[0];
                int nCol = col + dir[1];
                // cout << nRow << " " << nCol << endl;

                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                    grid[nRow][nCol] == 1) {
                    grid[nRow][nCol] = 2;
                    qu.push({{nRow, nCol}, minute + 1});
                    fresh--;
                }
            }
        }
        if (fresh>0) return -1;

        return res;
    }
};