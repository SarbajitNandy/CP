class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int y[3] = {0,0,0}, ny[3] = {0,0,0};

        int n = grid.size();
        int mid = n/2;

        for(int i=0;i<n;i++) {
            for(int j =0;j<n;j++) {
                // if a diagonal 
                int val = grid[i][j];
                if (i==j && i<=mid) {
                    y[val]++;
                } else if (i+j==n-1 && j >= mid) {
                    y[val]++;
                } else if (j==mid && i>=mid) {
                    y[val]++;
                } else ny[val]++;
            }
        }

        // cout << y[0] << " " << y[1] << " " << y[2] << endl;
        // cout << ny[0] << " " << ny[1] << " " << ny[2] << endl;

        int ysum = y[0]+y[1]+y[2];
        int nysum = ny[0]+ny[1]+ny[2];
        int mn = INT_MAX;

        for(int i = 0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if (i==j) continue;

                int ycost = ysum - y[i];
                int nycost = nysum - ny[j];

                mn = min(mn, ycost + nycost);
            }
        }

        return mn;

    }
};